#include <BearLibTerminal.h>
#include "../include/game/systems/RenderSystem.h"
#include "../include/lib/ecs/entity_manager.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/TextureComponent.h"

RenderSystem::RenderSystem(EntityManager* const em, SystemManager* const sm) : ISystem(em, sm) {}

void RenderSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PositionComponent>()) {
      auto pc = entity.Get<PositionComponent>();
      auto tc = entity.Get<TextureComponent>();
      terminal_put(pc->pos_.x, pc->pos_.y, tc->symbol_);
    }
  }
}
