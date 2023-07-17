#include "../include/game/systems/PursuerSystem.h"

PursuerSystem::PursuerSystem(EntityManager* const em, SystemManager* const sm, Context* ctx, LevelManager* levelManager,
                             int player_id)
    : ISystem(em, sm), em_(*em), ctx_(*ctx), levelManager_(*levelManager), player_id_(player_id) {}

void PursuerSystem::OnUpdate() {
  // playerComponents
  auto player = em_.Get(player_id_);
  auto playerPosition = player->Get<PositionComponent>();
  auto playerTransform = player->Get<TransformComponent>();
  auto playerControl = player->Get<ControlComponent>();
  auto playerHealth = player->Get<HealthComponent>();
  auto playerDamage = player->Get<DamageComponent>();
  auto playerSocialCredit = player->Get<SocialCreditComponent>();
  for (auto& enemy : GetEntityManager()) {
    if (enemy.Contains<PositionComponent>() && enemy.Contains<TransformComponent>() && enemy.Contains<EnemyTag>()) {
      auto enemyPosition = enemy.Get<PositionComponent>();
      auto enemyTransform = enemy.Get<TransformComponent>();
      auto enemyHealth = enemy.Get<HealthComponent>();
      auto enemyDamage = enemy.Get<DamageComponent>();
      if (playerControl->left_pressed_ || playerControl->up_pressed_ || playerControl->right_pressed_ ||
          playerControl->down_pressed_) {
        if (playerPosition->position_.x < enemyPosition->position_.x) {
          enemyTransform->transform_vec2_ = LeftVec2;
        }
        if (playerPosition->position_.x > enemyPosition->position_.x) {
          enemyTransform->transform_vec2_ = RightVec2;
        }
        if (playerPosition->position_.y < enemyPosition->position_.y) {
          enemyTransform->transform_vec2_ = UpVec2;
        }
        if (playerPosition->position_.y > enemyPosition->position_.y) {
          enemyTransform->transform_vec2_ = DownVec2;
        }
        for (auto& obstacle : GetEntityManager()) {
          // enemy and player FIGHT
          if ((playerPosition->position_ + playerTransform->transform_vec2_) ==
              (enemyPosition->position_ + enemyTransform->transform_vec2_)) {
            if (enemyHealth->health_ > 0) {
              enemyHealth->health_ -= playerDamage->damage_;
              playerHealth->health_ -= enemyDamage->damage_;
              playerSocialCredit->social_credits_ += 10;
            }
            enemyTransform->transform_vec2_ = ZeroVec2;
            playerTransform->transform_vec2_ = ZeroVec2;
            if (enemyHealth->health_ <= 0) {
              GetEntityManagerPtr()->DeleteEntity(enemy.GetId());
            }
            if (playerHealth->health_ <= 0) {
              ctx_.scene_ = "game_over";
            }
          }
          // enemy and wife collision
          if (obstacle.Contains<WifeTag>()) {
            auto wifeHealth = obstacle.Get<HealthComponent>();
            auto wifePosition = obstacle.Get<PositionComponent>();
            if (wifePosition->position_ == enemyPosition->position_) {
              wifeHealth->health_ -= enemyDamage->damage_;
            }
          }
          // enemy and enemy collision
          if (obstacle.Contains<PositionComponent>() && obstacle.Contains<TransformComponent>() &&
              obstacle.Contains<EnemyTag>() && (enemy.GetId() != obstacle.GetId())) {
            auto obstaclePosition = obstacle.Get<PositionComponent>();
            auto obstacleTransform = obstacle.Get<TransformComponent>();
            if ((enemyPosition->position_ + enemyTransform->transform_vec2_) ==
                (obstaclePosition->position_ + obstacleTransform->transform_vec2_)) {
              enemyTransform->transform_vec2_ = ZeroVec2;
            }
          }
          // enemy and walls collision
          if (obstacle.Contains<PositionComponent>() && obstacle.Contains<ObstacleTag>()) {
            auto obstaclePosition = obstacle.Get<PositionComponent>();
            if ((enemyPosition->position_ + enemyTransform->transform_vec2_) == obstaclePosition->position_) {
              enemyTransform->transform_vec2_ = ZeroVec2;
            }
          }
          // enemy and food collision
          if (obstacle.Contains<PositionComponent>() && obstacle.Contains<TakeableTag>()) {
            auto obstaclePosition = obstacle.Get<PositionComponent>();
            if ((enemyPosition->position_ + enemyTransform->transform_vec2_) == obstaclePosition->position_) {
              if (obstacle.Contains<SaturationComponent>()) {
                auto obstacleSaturation = obstacle.Get<SaturationComponent>();
                enemyHealth->health_ += obstacleSaturation->saturation_;
                obstacle.Delete<PositionComponent>();
                obstacle.Delete<TextureComponent>();
              }
            }
          }
        }
      }
    }
  }
  for (auto& wife : GetEntityManager()) {
    if (wife.Contains<WifeTag>()) {
      auto wifePosition = wife.Get<PositionComponent>();
      auto wifeTransform = wife.Get<TransformComponent>();
      auto wifeHealth = wife.Get<HealthComponent>();
      if (playerControl->left_pressed_ || playerControl->up_pressed_ || playerControl->right_pressed_ ||
          playerControl->down_pressed_) {
        if (playerPosition->position_.x < wifePosition->position_.x) {
          wifeTransform->transform_vec2_ = LeftVec2;
        }
        if (playerPosition->position_.x > wifePosition->position_.x) {
          wifeTransform->transform_vec2_ = RightVec2;
        }
        if (playerPosition->position_.y < wifePosition->position_.y) {
          wifeTransform->transform_vec2_ = UpVec2;
        }
        if (playerPosition->position_.y > wifePosition->position_.y) {
          wifeTransform->transform_vec2_ = DownVec2;
        }
        if ((wifePosition->position_ + wifeTransform->transform_vec2_) == playerPosition->position_) {
          wifeTransform->transform_vec2_ = ZeroVec2;
        }
        if (wifePosition->position_ == playerPosition->position_) {
          playerHealth->health_ += 50;
        }
        for (auto& obstacle : GetEntityManager()) {
          if (obstacle.Contains<PositionComponent>() && obstacle.Contains<ObstacleTag>()) {
            auto obstaclePosition = obstacle.Get<PositionComponent>();
            if ((wifePosition->position_ + wifeTransform->transform_vec2_) == obstaclePosition->position_) {
              wifeTransform->transform_vec2_ = ZeroVec2;
            }
          }
        }
      }
    }
  }
}
