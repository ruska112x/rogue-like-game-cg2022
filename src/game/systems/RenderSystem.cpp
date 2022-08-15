#include "../include/game/systems/RenderSystem.h"

RenderSystem::RenderSystem(EntityManager* const em, SystemManager* const sm) : ISystem(em, sm) {}

void RenderSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PositionComponent>() && entity.Contains<TextureComponent>()) {
      auto pc = entity.Get<PositionComponent>();
      auto tc = entity.Get<TextureComponent>();
      terminal_put(static_cast<int>(pc->pos_.x), static_cast<int>(pc->pos_.y), tc->symbol_);
    }
  }
}
