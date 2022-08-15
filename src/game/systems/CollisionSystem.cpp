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

      if (key == cc->up_btn_) {
        for (auto& obstacle : GetEntityManager()) {
          if (obstacle.Contains<ObstacleTag>()) {
            auto epc = entity.Get<PositionComponent>();
            auto opc = obstacle.Get<PositionComponent>();
            if ((epc->pos_ + UpVec2) != opc->pos_) {
              mc->speed_ = UpVec2;
            }
          }
        }
      }
      if (key == cc->right_btn_) {
        for (auto& obstacle : GetEntityManager()) {
          if (obstacle.Contains<ObstacleTag>()) {
            auto epc = entity.Get<PositionComponent>();
            auto opc = obstacle.Get<PositionComponent>();
            if ((epc->pos_ + RightVec2) != opc->pos_) {
              mc->speed_ = RightVec2;
            }
          }
        }
      }
      if (key == cc->down_btn_) {
        for (auto& obstacle : GetEntityManager()) {
          if (obstacle.Contains<ObstacleTag>()) {
            auto epc = entity.Get<PositionComponent>();
            auto opc = obstacle.Get<PositionComponent>();
            if ((epc->pos_ + DownVec2) != opc->pos_) {
              mc->speed_ = DownVec2;
            }
          }
        }
      }
      if (key == cc->left_btn_) {
        for (auto& obstacle : GetEntityManager()) {
          if (obstacle.Contains<ObstacleTag>()) {
            auto epc = entity.Get<PositionComponent>();
            auto opc = obstacle.Get<PositionComponent>();
            if ((epc->pos_ + LeftVec2) != opc->pos_) {
              mc->speed_ = LeftVec2;
            }
          }
        }
      }
    }
  }
}
