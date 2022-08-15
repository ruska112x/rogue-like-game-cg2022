#include "../include/game/systems/MovementSystem.h"

MovementSystem::MovementSystem(EntityManager* const em, SystemManager* const sm)
    : ISystem(em, sm) {}

void MovementSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PositionComponent>() && entity.Contains<MovementComponent>()) {
      auto pc = entity.Get<PositionComponent>();
      auto mc = entity.Get<MovementComponent>();

      pc->pos_ += mc->speed_;
      mc->speed_ = Vec2(ZeroVec2);
    }
  }
}
