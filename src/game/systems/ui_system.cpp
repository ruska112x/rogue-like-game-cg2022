#include "../include/game/systems/ui_system.h"

UISystem::UISystem(EntityManager *em, SystemManager *sm, int player_id)
    : ISystem(em, sm), em_(*em), player_id_(player_id) {}

void UISystem::OnUpdate() {
  auto player = em_.Get(player_id_);
  auto phc = player->Get<HealthComponent>();
  auto ppc = player->Get<PositionComponent>();
  auto psc = player->Get<StepComponent>();
  terminal_printf(1, 17, "Health: %d", phc->health_);
  terminal_printf(1, 18, "x: %d", static_cast<int>(ppc->position_.x));
  terminal_printf(1, 19, "y: %d", static_cast<int>(ppc->position_.y));
  terminal_printf(1, 20, "Steps: %d", psc->step_count_);
  terminal_printf(1, 21, "Max Steps: %d", psc->max_steps_on_level_);
}
