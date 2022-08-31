#include "../include/game/systems/ui_system.h"

UISystem::UISystem(EntityManager *em, SystemManager *sm, int player_id)
    : ISystem(em, sm), em_(*em), player_id_(player_id) {}

void UISystem::OnUpdate() {
  auto player = em_.Get(player_id_);
  auto phc = player->Get<HealthComponent>();
  auto pdc = player->Get<DamageComponent>();
  auto ppc = player->Get<PositionComponent>();
  auto psc = player->Get<StepComponent>();
  auto pscc = player->Get<SocialCreditComponent>();
  terminal_printf(1, 17, "HP: %d", phc->health_);
  terminal_printf(1, 18, "DP: %d", pdc->damage_);
  terminal_printf(18, 17, "x: %d", static_cast<int>(ppc->position_.x));
  terminal_printf(18, 18, "y: %d", static_cast<int>(ppc->position_.y));
  terminal_printf(1, 21, "Social Credits: %d", pscc->social_credits_);
  terminal_printf(1, 19, "Steps: %d", psc->step_count_);
  terminal_printf(1, 20, "Max Steps: %d", psc->max_steps_on_level_);
}
