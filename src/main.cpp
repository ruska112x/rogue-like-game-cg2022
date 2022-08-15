#include "../include/game/main.h"

int main() {
  terminal_open();
  terminal_set("window: title='RogueLG', size = 63x31;"
      "font: /home/ruska/aksur/programming/roguelg_esc/assets/fonts/jbm.ttf, size=16");
  terminal_refresh();
  Controls controls;
  const Engine engine{};

  auto Player = engine.GetEntityManager()->CreateEntity();
  Player->Add<PositionComponent>(Vec2(1, 1));
  Player->Add<MovementComponent>(Vec2(ZeroVec2));
  Player->Add<ControlComponent>(TK_UP, TK_RIGHT, TK_DOWN, TK_LEFT);
  Player->Add<TextureComponent>('@');
  Player->Add<CollisionComponent>();

  auto Wall0 = engine.GetEntityManager()->CreateEntity();
  Wall0->Add<PositionComponent>(Vec2(2, 2));
  Wall0->Add<TextureComponent>('#');
  Wall0->Add<ObstacleTag>();

//  auto Wall1 = engine.GetEntityManager()->CreateEntity();
//  Wall1->Add<PositionComponent>(Vec2(4, 2));
//  Wall1->Add<TextureComponent>('#');
//  Wall1->Add<ObstacleTag>();

  auto systemManager = engine.GetSystemManager();

  systemManager->AddSystem<RenderSystem>();
  systemManager->AddSystem<CollisionSystem>(&controls);
  systemManager->AddSystem<MovementSystem>();

  while (true) {
    terminal_clear();
    engine.OnUpdate();

    terminal_refresh();
  }

  terminal_close();
}
