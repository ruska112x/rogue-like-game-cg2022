#include "../include/game/systems/collision_system.h"

#include <string>
#include <utility>

CollisionSystem::CollisionSystem(EntityManager* const em, SystemManager* const sm, Context* ctx,
                                 LevelManager* levelManager, std::string prev_level, std::string next_level)
    : ISystem(em, sm),
      ctx_(*ctx),
      levelManager_(*levelManager),
      prev_level_(std::move(prev_level)),
      next_level_(std::move(next_level)) {}

void CollisionSystem::OnUpdate() {
  SceneChanger sceneChanger(&ctx_);
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PositionComponent>() && entity.Contains<TransformComponent>() && entity.Contains<EnemyTag>()) {
      auto epc = entity.Get<PositionComponent>();
      auto etc = entity.Get<TransformComponent>();
      for (auto& obstacle : GetEntityManager()) {
        if (obstacle.Contains<PositionComponent>() && obstacle.Contains<TransformComponent>() &&
            obstacle.Contains<EnemyTag>() && (entity.GetId() != obstacle.GetId())) {
          auto opc = obstacle.Get<PositionComponent>();
          auto otc = obstacle.Get<TransformComponent>();
          if ((epc->position_ + etc->transform_vec2_) == (opc->position_ + otc->transform_vec2_)) {
            etc->transform_vec2_ = ZeroVec2;
            //            otc->transform_vec2_ = ZeroVec2;
          }
        }
      }
    }
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
            for (int i = 0; i < levelManager_.food_pos_.size(); ++i) {
              if (opc->position_ == levelManager_.food_pos_[i]) {
                levelManager_.food_pos_.erase(levelManager_.food_pos_.cbegin() + i);
                break;
              }
            }
            GetEntityManagerPtr()->DeleteEntity(obstacle.GetId());
          }
        }
        if (obstacle.Contains<EnemyTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          auto otc = obstacle.Get<TransformComponent>();
          if ((epc->position_ + etc->transform_vec2_) == (opc->position_ + otc->transform_vec2_)) {
            auto ehc = entity.Get<HealthComponent>();
            auto edc = entity.Get<DamageComponent>();
            auto ohc = obstacle.Get<HealthComponent>();
            auto odc = obstacle.Get<DamageComponent>();
            ehc->health_ -= odc->damage_;
            ohc->health_ -= edc->damage_;
            etc->transform_vec2_ = ZeroVec2;
            otc->transform_vec2_ = ZeroVec2;
          }
        }
        if (obstacle.Contains<PrevDoorTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->position_ + etc->transform_vec2_) == opc->position_) {
            sceneChanger.changeLevel(prev_level_);
          }
        }
        if (obstacle.Contains<NextDoorTag>()) {
          auto opc = obstacle.Get<PositionComponent>();
          if ((epc->position_ + etc->transform_vec2_) == opc->position_) {
            sceneChanger.changeLevel(next_level_);
            levelManager_.player_pos_.x = opc->position_.x - 1;
            levelManager_.player_pos_.y = opc->position_.y;
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
