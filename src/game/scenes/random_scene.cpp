#include "../include/game/scenes/random_scene.h"

#include <string>
#include <utility>

RandomScene::RandomScene(Context *ctx, const Controls &controls, std::string next_level)
    : IScene(ctx), controls_(controls), next_level_(std::move(next_level)) {
  levelManager_.GetRandomLevel();
}

void RandomScene::OnCreate() {
  if (ctx_->restart) {
    levelManager_.GetRandomLevel();
    ctx_->restart = false;
  }
  auto next_door = engine.GetEntityManager()->CreateEntity();
  next_door->Add<PositionComponent>(levelManager_.next_door_pos_);
  next_door->Add<TextureComponent>('>');
  next_door->Add<ColorComponent>(color_from_name("purple"));
  next_door->Add<NextDoorTag>();

  auto prev_door = engine.GetEntityManager()->CreateEntity();
  prev_door->Add<PositionComponent>(levelManager_.prev_door_pos_);
  prev_door->Add<TextureComponent>('<');
  prev_door->Add<ColorComponent>(color_from_name("green"));
  prev_door->Add<PrevDoorTag>();

  for (auto wall_pos : levelManager_.walls_pos_) {
    auto wall = engine.GetEntityManager()->CreateEntity();
    wall->Add<PositionComponent>(Vec2(wall_pos.x, wall_pos.y));
    wall->Add<TextureComponent>('#');
    wall->Add<ObstacleTag>();
  }

  for (auto food_pos : levelManager_.food_pos_) {
    auto food = engine.GetEntityManager()->CreateEntity();
    food->Add<PositionComponent>(Vec2(food_pos.x, food_pos.y));
    food->Add<TextureComponent>('%');
    food->Add<ColorComponent>(color_from_name("pink"));
    food->Add<SaturationComponent>(50);
    food->Add<TakeableTag>();
  }

  for (auto enemy_pos : levelManager_.enemy_pos_) {
    auto enemy = engine.GetEntityManager()->CreateEntity();
    enemy->Add<PositionComponent>(enemy_pos);
    enemy->Add<TransformComponent>(ZeroVec2);
    enemy->Add<TextureComponent>('E');
    enemy->Add<ColorComponent>(color_from_name("red"));
    enemy->Add<EnemyTag>();
    enemy->Add<ObstacleTag>();
    enemy->Add<HealthComponent>(250);
    enemy->Add<DamageComponent>(100);
  }

  auto player = engine.GetEntityManager()->CreateEntity();
  player->Add<PositionComponent>(levelManager_.player_pos_);
  player->Add<TextureComponent>('@');
  player->Add<ColorComponent>(color_from_name("cyan"));
  player->Add<HealthComponent>(ctx_->player_health_);
  player->Add<StepComponent>(ctx_->player_max_steps_);
  player->Add<ControlComponent>(TK_LEFT, TK_UP, TK_RIGHT, TK_DOWN);
  player->Add<TransformComponent>(ZeroVec2);
  player->Add<DamageComponent>(ctx_->player_damage_);
  player->Add<ObstacleTag>();

  auto player_id = player->GetId();

  auto systemManager = engine.GetSystemManager();

  systemManager->AddSystem<RenderSystem>(ctx_);
  systemManager->AddSystem<ControlSystem>(controls_);
  systemManager->AddSystem<CollisionSystem>(ctx_, &levelManager_, "-", next_level_);
  systemManager->AddSystem<TransformSystem>();
  systemManager->AddSystem<UISystem>(player_id);
  systemManager->AddSystem<GameOverSystem>(ctx_, player_id);
  systemManager->AddSystem<DeathSystem>();
  systemManager->AddSystem<PursuerSystem>(ctx_, &levelManager_, player_id);
}

void RandomScene::OnRender() {
  if (ctx_->restart) {
    levelManager_.GetRandomLevel();
  }
  engine.OnUpdate();
  if (controls_.IsPressed(TK_ESCAPE)) {
    ctx_->restart = true;
    ctx_->scene_ = "title";
  }
}

void RandomScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
