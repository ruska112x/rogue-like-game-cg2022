#include "../include/game/systems/render_system.h"

RenderSystem::RenderSystem(EntityManager* const em, SystemManager* const sm, Context* ctx)
    : ISystem(em, sm), ctx_(*ctx) {}

void RenderSystem::OnUpdate() {
  if (ctx_.sprite) {
    terminal_set("0x23: assets/sprites/wall.png");
    terminal_set("0x3e: assets/sprites/next_door.png");
    terminal_set("0x3c: assets/sprites/prev_door.png");
    terminal_set("0x25: assets/sprites/food.png");
    terminal_set("0x45: assets/sprites/enemy.png");
    terminal_set("0x2d: assets/sprites/key.png");
    terminal_set("0x26: assets/sprites/cat.png");
    terminal_set("0x7e: assets/sprites/redbull.png");
    terminal_set("0x40: assets/sprites/player.png");
    for (auto& entity : GetEntityManager()) {
      if (entity.Contains<PositionComponent>() && entity.Contains<TextureComponent>()) {
        auto epc = entity.Get<PositionComponent>();
        auto etc = entity.Get<TextureComponent>();
        if (etc->symbol_ == '#') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x23);
        } else if (etc->symbol_ == '>') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x3e);
        } else if (etc->symbol_ == '<') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x3c);
        } else if (etc->symbol_ == '%') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x25);
        } else if (etc->symbol_ == 'E') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x45);
        } else if (etc->symbol_ == '-') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x2d);
        } else if (etc->symbol_ == '&') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x26);
        } else if (etc->symbol_ == '~') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x7e);
        } else if (etc->symbol_ == '@') {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), 0x40);
        } else {
          terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), etc->symbol_);
        }
      }
    }
  } else {
    for (auto& entity : GetEntityManager()) {
      if (entity.Contains<PositionComponent>() && entity.Contains<TextureComponent>()) {
        auto epc = entity.Get<PositionComponent>();
        auto etc = entity.Get<TextureComponent>();
        if (entity.Contains<ColorComponent>()) {
          auto ecc = entity.Get<ColorComponent>();
          terminal_color(ecc->color_);
          terminal_printf(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), "%c", etc->symbol_);
          terminal_color(color_from_name("white"));
        } else {
          terminal_printf(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), "%c", etc->symbol_);
        }
      }
    }
  }
}
