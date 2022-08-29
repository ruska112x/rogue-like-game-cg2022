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
  if (ctx_->restart) {
    levelManager_.GetLevel(level_file_);
    ctx_->p_health_ = 1000;
    ctx_->p_steps_ = 0;
    ctx_->p_max_steps_ = 512;
    ctx_->p_damage_ = 100;
    ctx_->p_credits_ = 100;
    ctx_->restart = false;
  }

  auto systemManager = engine.GetSystemManager();

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

  for (auto food_pos : levelManager_.food_pos_) {
    auto food = engine.GetEntityManager()->CreateEntity();
    food->Add<PositionComponent>(Vec2(food_pos.x, food_pos.y));
    food->Add<TextureComponent>('%');
    food->Add<ColorComponent>(color_from_name("pink"));
    food->Add<SaturationComponent>(50);
    food->Add<TakeableTag>();
  }

  auto close = engine.GetEntityManager()->CreateEntity();
  if (ctx_->scene_ != "secret" && ctx_->scene_ != "random") {
    close->Add<PositionComponent>(levelManager_.close_pos_);
    close->Add<ObstacleTag>();
    close->Add<TextureComponent>('#');
  }
  auto close_id = close->GetId();

  auto key = engine.GetEntityManager()->CreateEntity();
  key->Add<PositionComponent>(levelManager_.key_pos_);
  key->Add<TextureComponent>('-');
  key->Add<TakeableTag>();
  key->Add<OpenDoorComponent>();
  key->Add<ColorComponent>(color_from_name("yellow"));

  auto key_id = key->GetId();

  for (auto enemy_pos : levelManager_.enemy_pos_) {
    auto enemy = engine.GetEntityManager()->CreateEntity();
    enemy->Add<PositionComponent>(enemy_pos);
    enemy->Add<TransformComponent>(ZeroVec2);
    enemy->Add<TextureComponent>('E');
    enemy->Add<ColorComponent>(color_from_name("red"));
    enemy->Add<EnemyTag>();
    enemy->Add<ObstacleTag>();
    enemy->Add<HealthComponent>(200);
    enemy->Add<DamageComponent>(100);
  }

  auto wife = engine.GetEntityManager()->CreateEntity();
  if (ctx_->scene_ == "level3") {
    wife->Add<PositionComponent>(levelManager_.wife_pos_);
    wife->Add<TextureComponent>('&');
    wife->Add<ColorComponent>(color_from_name("light green"));
    wife->Add<WifeTag>();
    wife->Add<TransformComponent>(ZeroVec2);
    wife->Add<HealthComponent>(500);
  }

  for (auto wall_pos : levelManager_.walls_pos_) {
    auto wall = engine.GetEntityManager()->CreateEntity();
    wall->Add<PositionComponent>(Vec2(wall_pos.x, wall_pos.y));
    wall->Add<TextureComponent>('#');
    wall->Add<ObstacleTag>();
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

  systemManager->AddSystem<RenderSystem>(ctx_);
  systemManager->AddSystem<CheatSystem>(controls_, ctx_);
  systemManager->AddSystem<ControlSystem>(controls_);
  systemManager->AddSystem<CollisionSystem>(ctx_, &levelManager_, prev_level_, next_level_);
  systemManager->AddSystem<TransformSystem>();
  systemManager->AddSystem<UISystem>(player_id_);
  systemManager->AddSystem<GameOverSystem>(ctx_, player_id_);
  systemManager->AddSystem<DeathSystem>();
  systemManager->AddSystem<PursuerSystem>(ctx_, &levelManager_, player_id_);
  systemManager->AddSystem<DoorSystem>(&levelManager_, close_id, key_id);
}

void GameScene::OnRender() {
  if (ctx_->restart) {
    levelManager_.GetLevel(level_file_);
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

void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
