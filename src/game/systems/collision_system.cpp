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
      auto ecc = entity.Get<ControlComponent>();
      auto epc = entity.Get<PositionComponent>();
      auto etc = entity.Get<TransformComponent>();
      if (ecc->left_pressed_) {
        etc->transform_vec2_ = LeftVec2;
      }
      if (ecc->up_pressed_) {
        etc->transform_vec2_ = UpVec2;
      }
      if (ecc->right_pressed_) {
        etc->transform_vec2_ = RightVec2;
      }
      if (ecc->down_pressed_) {
        etc->transform_vec2_ = DownVec2;
      }
      for (auto& obstacle : GetEntityManager()) {
        if (obstacle.Contains<ObstacleTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->position_ + etc->transform_vec2_) == opc->position_) {
            etc->transform_vec2_ = ZeroVec2;
          }
        }
        if (obstacle.Contains<TakeableTag>() && obstacle.Contains<SaturationComponent>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->position_ + etc->transform_vec2_) == opc->position_) {
            auto ehc = entity.Get<HealthComponent>();
            auto osc = obstacle.Get<SaturationComponent>();
            ehc->health_ += osc->saturation_;
            GetEntityManagerPtr()->DeleteEntity(obstacle.GetId());
          }
        }
        if (obstacle.Contains<NextDoorTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->position_ + etc->transform_vec2_) == opc->position_) {
            sceneChanger.changeLevel(next_level_);
          }
        }
        if (obstacle.Contains<PrevDoorTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->position_ + etc->transform_vec2_) == opc->position_) {
            sceneChanger.changeLevel(prev_level_);
          }
        }
      }
      ecc->left_pressed_ = false;
      ecc->up_pressed_ = false;
      ecc->right_pressed_ = false;
      ecc->down_pressed_ = false;
    }
  }
}
