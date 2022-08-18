#include "../include/game/scenes/game_scene.h"

GameScene::GameScene(Context *const ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void GameScene::OnCreate() {
  {
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<PositionComponent>(Vec2(7, 7));
    player->Add<TextureComponent>('@');
    player->Add<ColorComponent>(color_from_name("cyan"));
    player->Add<HealthComponent>(1000);
    player->Add<ControlComponent>(TK_LEFT, TK_UP, TK_RIGHT, TK_DOWN);
    player->Add<TransformComponent>(ZeroVec2);
  }

  for (int i = 0; i < 5; ++i) {
    auto wall = engine.GetEntityManager()->CreateEntity();
    wall->Add<PositionComponent>(Vec2(i, i));
    wall->Add<TextureComponent>('#');
    wall->Add<ObstacleTag>();
  }

  {
    auto food = engine.GetEntityManager()->CreateEntity();
    food->Add<PositionComponent>(Vec2(4, 7));
    food->Add<TextureComponent>('%');
    food->Add<ColorComponent>(color_from_name("red"));
    food->Add<SaturationComponent>(5);
    food->Add<TakeableTag>();
  }
  {
    auto systemManager = engine.GetSystemManager();

    systemManager->AddSystem<RenderSystem>();
    systemManager->AddSystem<ControlSystem>(controls_);
    systemManager->AddSystem<CollisionSystem>();
    systemManager->AddSystem<TransformSystem>();
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
