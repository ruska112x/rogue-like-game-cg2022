#include "../include/game/main.h"

int main() {
  terminal_open();
  terminal_set(
      "window: title='RogueLG', cellsize = 16x16, size = 63x43;"
      "font: /home/ruska/aksur/programming/roguelg/assets/fonts/16.ttf, size=24");
  terminal_refresh();

  const Engine engine{};
  Controls controls;

  auto player = engine.GetEntityManager()->CreateEntity();
  player->Add<PositionComponent>(OnesVec2);
  player->Add<TextureComponent>('@');
  player->Add<ColorComponent>(color_from_name("cyan"));
  player->Add<HealthComponent>(1000);
  player->Add<ControlComponent>(TK_LEFT, TK_UP, TK_RIGHT, TK_DOWN);
  player->Add<CollisionComponent>();
  player->Add<TransformComponent>();

  auto wall = engine.GetEntityManager()->CreateEntity();
  wall->Add<PositionComponent>(Vec2(4, 4));
  wall->Add<TextureComponent>('#');
  wall->Add<ObstacleTag>();

  auto systemManager = engine.GetSystemManager();

  systemManager->AddSystem<RenderSystem>();
  systemManager->AddSystem<ControlSystem>(&controls);
  systemManager->AddSystem<CollisionSystem>();
  systemManager->AddSystem<TransformSystem>();

  while (true) {
    terminal_clear();
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE) || controls.IsPressed(TK_ESCAPE)) {
      break;
    }
    engine.OnUpdate();
    controls.Reset();
    terminal_refresh();
  }

  terminal_close();
}
