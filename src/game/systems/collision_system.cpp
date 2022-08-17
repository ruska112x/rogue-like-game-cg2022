#include "../include/game/systems/collision_system.h"

CollisionSystem::CollisionSystem(EntityManager* const em, SystemManager* const sm) : ISystem(em, sm) {}

void CollisionSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<ControlComponent>() && entity.Contains<TransformComponent>()) {
      auto econtrol = entity.Get<ControlComponent>();
      auto eposition = entity.Get<PositionComponent>();
      auto etransform = entity.Get<TransformComponent>();
      if (econtrol->left_pressed_) {
        etransform->transform_vec2_ = LeftVec2;
      }
      if (econtrol->up_pressed_) {
        etransform->transform_vec2_ = UpVec2;
      }
      if (econtrol->right_pressed_) {
        etransform->transform_vec2_ = RightVec2;
      }
      if (econtrol->down_pressed_) {
        etransform->transform_vec2_ = DownVec2;
      }
      for (auto& obstacle : GetEntityManager()) {
        if (obstacle.Contains<ObstacleTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((eposition->position_ + etransform->transform_vec2_) == opc->position_) {
            etransform->transform_vec2_ = ZeroVec2;
          }
        }
        if (obstacle.Contains<TakeableTag>() && obstacle.Contains<SaturationComponent>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((eposition->position_ + etransform->transform_vec2_) == opc->position_) {
            auto ehc = entity.Get<HealthComponent>();
            auto osc = obstacle.Get<SaturationComponent>();
            ehc->health_ += osc->saturation_;
            GetEntityManagerPtr()->DeleteEntity(obstacle.GetId());
            printf("%d", ehc->health_);
          }
        }
      }
      econtrol->left_pressed_ = false;
      econtrol->up_pressed_ = false;
      econtrol->right_pressed_ = false;
      econtrol->down_pressed_ = false;
    }
  }
}
