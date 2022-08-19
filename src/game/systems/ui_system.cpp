#include "../include/game/systems/ui_system.h"

UISystem::UISystem(EntityManager *em, SystemManager *sm, int player_id)
    : ISystem(em, sm), em_(*em), player_id_(player_id) {}

void UISystem::OnUpdate() {
  auto player = em_.Get(player_id_);
  auto phc = player->Get<HealthComponent>();
  auto ppc = player->Get<PositionComponent>();
  auto psc = player->Get<StepComponent>();
  terminal_printf(1, 37, "Health: %d", phc->health_);
  terminal_printf(1, 38, "x: %d", static_cast<int>(ppc->position_.x));
  terminal_printf(1, 39, "y: %d", static_cast<int>(ppc->position_.y));
  terminal_printf(1, 40, "Steps: %d", psc->step_count_);
  terminal_printf(1, 41, "Max Steps: %d", psc->max_steps_on_level_);
}
