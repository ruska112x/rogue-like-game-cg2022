#include "../include/game/systems/transform_system.h"

TransformSystem::TransformSystem(EntityManager* const em, SystemManager* const sm) : ISystem(em, sm) {}

void TransformSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PositionComponent>() && entity.Contains<TransformComponent>()) {
      auto epc = entity.Get<PositionComponent>();
      auto etc = entity.Get<TransformComponent>();
      epc->position_ += etc->transform_vec2_;
      if (entity.Contains<StepComponent>()) {
        auto esc = entity.Get<StepComponent>();
        esc->step_count_ += static_cast<int>(etc->transform_vec2_.Magnitude());
      }
      if (entity.Contains<ControlComponent>()) {
        etc->transform_vec2_ = ZeroVec2;
      }
    }
  }
}
