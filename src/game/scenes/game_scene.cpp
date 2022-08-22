#include "../include/game/scenes/game_scene.h"

#include <string>

GameScene::GameScene(Context* const ctx, const Controls& controls, std::string level_file, std::string prev_level,
                     std::string next_level)
    : IScene(ctx),
      controls_(controls),
      level_file_(std::move(level_file)),
      prev_level_(std::move(prev_level)),
      next_level_(std::move(next_level)) {
  levelManager_.GetLevel(level_file_);
}

void GameScene::OnCreate() {
  auto player = engine.GetEntityManager()->CreateEntity();
  player->Add<PositionComponent>(levelManager_.player_pos_);
  player->Add<TextureComponent>('@');
  player->Add<ColorComponent>(color_from_name("cyan"));
  player->Add<HealthComponent>(1000);
  player->Add<StepComponent>(128);
  player->Add<ControlComponent>(TK_LEFT, TK_UP, TK_RIGHT, TK_DOWN);
  player->Add<TransformComponent>(ZeroVec2);
  player->Add<DamageComponent>(50);

  for (auto enemy_pos : levelManager_.enemy_pos_) {
    auto enemy = engine.GetEntityManager()->CreateEntity();
    enemy->Add<PositionComponent>(enemy_pos);
    enemy->Add<TextureComponent>('E');
    enemy->Add<ColorComponent>(color_from_name("red"));
    enemy->Add<EnemyTag>();
    enemy->Add<HealthComponent>(100);
    enemy->Add<DamageComponent>(1);
  }

  auto player_id = player->GetId();

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

  auto systemManager = engine.GetSystemManager();

  systemManager->AddSystem<RenderSystem>();
  systemManager->AddSystem<ControlSystem>(controls_);
  systemManager->AddSystem<CollisionSystem>(ctx_, &levelManager_, prev_level_, next_level_);
  systemManager->AddSystem<TransformSystem>();
  systemManager->AddSystem<UISystem>(player_id);
  systemManager->AddSystem<GameOverSystem>(ctx_, player_id);
  systemManager->AddSystem<DeathSystem>();
}

void GameScene::OnRender() {
  engine.OnUpdate();
}

void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
