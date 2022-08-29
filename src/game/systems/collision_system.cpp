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
    if (entity.Contains<PositionComponent>() && entity.Contains<TransformComponent>() &&
        entity.Contains<ControlComponent>() && entity.Contains<HealthComponent>()) {
      // player components
      auto entityPosition = entity.Get<PositionComponent>();
      auto entityTransform = entity.Get<TransformComponent>();
      auto entityControl = entity.Get<ControlComponent>();
      auto entityHealth = entity.Get<HealthComponent>();
      auto entitySocialCredit = entity.Get<SocialCreditComponent>();
      if (entityControl->left_pressed_) {
        entityTransform->transform_vec2_ = LeftVec2;
      }
      if (entityControl->up_pressed_) {
        entityTransform->transform_vec2_ = UpVec2;
      }
      if (entityControl->right_pressed_) {
        entityTransform->transform_vec2_ = RightVec2;
      }
      if (entityControl->down_pressed_) {
        entityTransform->transform_vec2_ = DownVec2;
      }
      for (auto& obstacle : GetEntityManager()) {
        // player and walls collision
        if (obstacle.Contains<PositionComponent>() && obstacle.Contains<ObstacleTag>() &&
            (entity.GetId() != obstacle.GetId())) {
          auto obstaclePosition = obstacle.Get<PositionComponent>();
          if ((entityPosition->position_ + entityTransform->transform_vec2_) == obstaclePosition->position_) {
            entityTransform->transform_vec2_ = ZeroVec2;
          }
        }
        // player and takeable collision
        if (obstacle.Contains<PositionComponent>() && obstacle.Contains<TakeableTag>()) {
          auto obstaclePosition = obstacle.Get<PositionComponent>();
          if ((entityPosition->position_ + entityTransform->transform_vec2_) == obstaclePosition->position_) {
            if (obstacle.Contains<SaturationComponent>()) {
              auto obstacleSaturation = obstacle.Get<SaturationComponent>();
              entityHealth->health_ += obstacleSaturation->saturation_;
            }
            if (obstacle.Contains<OpenDoorComponent>()) {
              auto odc = obstacle.Get<OpenDoorComponent>();
              odc->is_open_ = true;
              levelManager_.key_pos_ = ZeroVec2;
              levelManager_.close_pos_ = ZeroVec2;
            }
            obstacle.Delete<PositionComponent>();
            obstacle.Delete<TextureComponent>();
          }
        }
        // player and prev_door collision
        if (obstacle.Contains<PositionComponent>() && obstacle.Contains<PrevDoorTag>()) {
          auto obstaclePosition = obstacle.Get<PositionComponent>();
          if ((entityPosition->position_ + entityTransform->transform_vec2_) == obstaclePosition->position_) {
            ctx_.restart = false;
            sceneChanger.changeLevel(prev_level_);
          }
        }
        // player and next_door collision
        if (obstacle.Contains<PositionComponent>() && obstacle.Contains<NextDoorTag>()) {
          auto obstaclePosition = obstacle.Get<PositionComponent>();
          if ((entityPosition->position_ + entityTransform->transform_vec2_) == obstaclePosition->position_) {
            sceneChanger.changeLevel(next_level_);
            if (!ctx_.random) {
              levelManager_.player_pos_.x = obstaclePosition->position_.x - 1;
              levelManager_.player_pos_.y = obstaclePosition->position_.y;
            }
          }
        }
      }
      entityControl->left_pressed_ = false;
      entityControl->up_pressed_ = false;
      entityControl->right_pressed_ = false;
      entityControl->down_pressed_ = false;
    }
  }
}
