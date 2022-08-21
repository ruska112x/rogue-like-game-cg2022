#include "../include/game/systems/collision_system.h"

#include <string>
#include <utility>

CollisionSystem::CollisionSystem(EntityManager* const em, SystemManager* const sm, Context* ctx, std::string prev_level,
                                 std::string next_level)
    : ISystem(em, sm), ctx_(*ctx), prev_level_(std::move(prev_level)), next_level_(std::move(next_level)) {}

void CollisionSystem::OnUpdate() {
  SceneChanger sceneChanger(&ctx_);
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
          }
        }
        if (obstacle.Contains<NextDoorTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((eposition->position_ + etransform->transform_vec2_) == opc->position_) {
            sceneChanger.changeLevel(next_level_);
          }
        }
        if (obstacle.Contains<PrevDoorTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((eposition->position_ + etransform->transform_vec2_) == opc->position_) {
            sceneChanger.changeLevel(prev_level_);
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
