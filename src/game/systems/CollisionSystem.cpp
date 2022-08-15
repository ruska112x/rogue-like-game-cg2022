#include "../include/game/systems/CollisionSystem.h"

CollisionSystem::CollisionSystem(EntityManager* em, SystemManager* sm, Controls* controls)
    : ISystem(em, sm), controls_(*controls) {}

void CollisionSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<ControlComponent>() && entity.Contains<PositionComponent>() &&
        entity.Contains<MovementComponent>()) {
      auto cc = entity.Get<ControlComponent>();
      auto mc = entity.Get<MovementComponent>();

      auto key = controls_.GetKey();

      Vec2 transfer_vec2_ = ZeroVec2;

      if (key == cc->up_btn_) {
        transfer_vec2_ = UpVec2;
      }
      if (key == cc->right_btn_) {
        transfer_vec2_ = RightVec2;
      }
      if (key == cc->down_btn_) {
        transfer_vec2_ = DownVec2;
      }
      if (key == cc->left_btn_) {
        transfer_vec2_ = LeftVec2;
      }
      for (auto& obstacle : GetEntityManager()) {
        if (obstacle.Contains<ObstacleTag>()) {
          auto epc = entity.Get<PositionComponent>();
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->pos_ + transfer_vec2_) == opc->pos_) {
            transfer_vec2_ = ZeroVec2;
          }
        }
      }
      mc->transfer_ = transfer_vec2_;
    }
  }
}
