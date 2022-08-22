#include "../include/game/systems/pursuer_system.h"

PursuerSystem::PursuerSystem(EntityManager* const em, SystemManager* const sm, int player_id)
    : ISystem(em, sm), em_(*em), player_id_(player_id) {}

void PursuerSystem::OnUpdate() {
  auto player = em_.Get(player_id_);
  auto ppc = player->Get<PositionComponent>();
  auto pcc = player->Get<ControlComponent>();
  auto ptc = player->Get<TransformComponent>();
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<EnemyTag>()) {
      auto epc = entity.Get<PositionComponent>();
      auto etc = entity.Get<TransformComponent>();
      if (pcc->left_pressed_ || pcc->up_pressed_ || pcc->right_pressed_ || pcc->down_pressed_) {
        if (ppc->position_.x < epc->position_.x) {
          etc->transform_vec2_ = LeftVec2;
        }
        if (ppc->position_.x > epc->position_.x) {
          etc->transform_vec2_ = RightVec2;
        }
        if (ppc->position_.y < epc->position_.y) {
          etc->transform_vec2_ = UpVec2;
        }
        if (ppc->position_.y > epc->position_.y) {
          etc->transform_vec2_ = DownVec2;
        }
      }
    }
  }
}
