#include "../include/game/systems/control_system.h"

ControlSystem::ControlSystem(EntityManager* const em, SystemManager* const sm, Controls* controls)
    : ISystem(em, sm), controls_(controls) {}

void ControlSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<ControlComponent>()) {
      auto ecc = entity.Get<ControlComponent>();
      if (controls_->IsPressed(ecc->btn_left_)) {
        ecc->left_pressed_ = true;
      }
      if (controls_->IsPressed(ecc->btn_up_)) {
        ecc->up_pressed_ = true;
      }
      if (controls_->IsPressed(ecc->btn_right_)) {
        ecc->right_pressed_ = true;
      }
      if (controls_->IsPressed(ecc->btn_down_)) {
        ecc->down_pressed_ = true;
      }
    }
  }
}
