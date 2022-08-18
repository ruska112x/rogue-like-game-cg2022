#include "../include/game/scenes/game_scene.h"

GameScene::GameScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void GameScene::OnCreate() {
  LevelManager levelManager;
  levelManager.GetLevel("/home/ruska/aksur/programming/roguelg/assets/levels/00.txt");

  auto player = engine.GetEntityManager()->CreateEntity();
  player->Add<PositionComponent>(levelManager.player_pos_);
  player->Add<TextureComponent>('@');
  player->Add<ColorComponent>(color_from_name("cyan"));
  player->Add<HealthComponent>(1000);
  player->Add<ControlComponent>(TK_LEFT, TK_UP, TK_RIGHT, TK_DOWN);
  player->Add<TransformComponent>(ZeroVec2);

  auto player_id = player->GetId();

  for (auto wall_pos : levelManager.walls_pos_) {
    auto wall = engine.GetEntityManager()->CreateEntity();
    wall->Add<PositionComponent>(Vec2(wall_pos.x, wall_pos.y));
    wall->Add<TextureComponent>('#');
    wall->Add<ObstacleTag>();
  }

  for (auto food_pos : levelManager.food_pos_) {
    auto food = engine.GetEntityManager()->CreateEntity();
    food->Add<PositionComponent>(Vec2(food_pos.x, food_pos.y));
    food->Add<TextureComponent>('%');
    food->Add<ColorComponent>(color_from_name("red"));
    food->Add<SaturationComponent>(50);
    food->Add<TakeableTag>();
  }

  {
    auto systemManager = engine.GetSystemManager();

    systemManager->AddSystem<RenderSystem>();
    systemManager->AddSystem<ControlSystem>(controls_);
    systemManager->AddSystem<CollisionSystem>();
    systemManager->AddSystem<TransformSystem>();
    systemManager->AddSystem<UISystem>(player_id);
  }
}

void GameScene::OnRender() {
  engine.OnUpdate();
  if (controls_.IsPressed(TK_X)) {
    ctx_->scene_ = "game_over";
  }
}

void GameScene::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
