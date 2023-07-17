#include "../include/game/scenes/RandomScene.h"

#include <string>
#include <utility>

RandomScene::RandomScene(Context *ctx, const Controls &controls, std::string next_level)
    : IScene(ctx), controls_(controls), next_level_(std::move(next_level)) {
  levelManager_.GetRandomLevel();
}

void RandomScene::OnCreate() {
  ctx_->p_health_ = 1000;
  ctx_->p_steps_ = 0;
  ctx_->p_max_steps_ = 256;
  ctx_->p_damage_ = 150;
  ctx_->p_credits_ = 100;
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
    enemy->Add<HealthComponent>(200);
    enemy->Add<DamageComponent>(50);
  }

  auto player = engine.GetEntityManager()->CreateEntity();
  player->Add<PositionComponent>(levelManager_.player_pos_);
  player->Add<TextureComponent>('@');
  player->Add<ColorComponent>(color_from_name("cyan"));
  player->Add<HealthComponent>(ctx_->p_health_);
  player->Add<StepComponent>(ctx_->p_steps_, ctx_->p_max_steps_);
  player->Add<SocialCreditComponent>(ctx_->p_credits_);
  player->Add<ControlComponent>(TK_LEFT, TK_UP, TK_RIGHT, TK_DOWN);
  player->Add<TransformComponent>(ZeroVec2);
  player->Add<DamageComponent>(ctx_->p_damage_);
  player->Add<ObstacleTag>();

  player_id_ = player->GetId();

  auto systemManager = engine.GetSystemManager();

  systemManager->AddSystem<RenderSystem>(ctx_);
  systemManager->AddSystem<ControlSystem>(controls_);
  systemManager->AddSystem<CollisionSystem>(ctx_, &levelManager_, "-", next_level_);
  systemManager->AddSystem<TransformSystem>();
  systemManager->AddSystem<UISystem>(player_id_);
  systemManager->AddSystem<GameOverSystem>(ctx_, player_id_);
  systemManager->AddSystem<DeathSystem>();
  systemManager->AddSystem<PursuerSystem>(ctx_, &levelManager_, player_id_);
}

void RandomScene::OnRender() {
  if (ctx_->restart) {
    levelManager_.GetRandomLevel();
  }
  engine.OnUpdate();
  ctx_->p_health_ = engine.GetEntityManager()->Get(player_id_)->Get<HealthComponent>()->health_;
  ctx_->p_damage_ = engine.GetEntityManager()->Get(player_id_)->Get<DamageComponent>()->damage_;
  ctx_->p_steps_ = engine.GetEntityManager()->Get(player_id_)->Get<StepComponent>()->step_count_;
  ctx_->p_credits_ = engine.GetEntityManager()->Get(player_id_)->Get<SocialCreditComponent>()->social_credits_;
  if (controls_.IsPressed(TK_ESCAPE)) {
    ctx_->restart = true;
    ctx_->scene_ = "title";
  }
}

void RandomScene::OnExit() {
  terminal_set(
      "0x23: none; 0x3e: none; 0x3c: none; 0x7e: none; 0x25: none; 0x45: none; 0x40: none; 0x2d: none; 0x26: none;");
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
