#include "../include/game/systems/render_system.h"

RenderSystem::RenderSystem(EntityManager* const em, SystemManager* const sm) : ISystem(em, sm) {}

void RenderSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PositionComponent>() && entity.Contains<TextureComponent>()) {
      auto epc = entity.Get<PositionComponent>();
      auto etc = entity.Get<TextureComponent>();
      if (entity.Contains<ColorComponent>()) {
        auto ecc = entity.Get<ColorComponent>();
        terminal_color(ecc->color_);
        terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), etc->symbol_);
        terminal_color(color_from_name("white"));
      } else {
        terminal_put(static_cast<int>(epc->position_.x), static_cast<int>(epc->position_.y), etc->symbol_);
      }
    }
  }
}
