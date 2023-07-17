#include "../include/game/systems/DeathSystem.h"

DeathSystem::DeathSystem(EntityManager* const em, SystemManager* const sm) : ISystem(em, sm) {}

void DeathSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<HealthComponent>() && entity.Contains<PositionComponent>() &&
        entity.Contains<TextureComponent>()) {
      auto ehc = entity.Get<HealthComponent>();
      if (ehc->health_ <= 0) {
        GetEntityManagerPtr()->Get(entity.GetId())->Delete<TextureComponent>();
      }
    }
  }
}
