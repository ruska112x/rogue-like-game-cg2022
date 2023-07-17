#include "../include/game/systems/game_over_system.h"

GameOverSystem::GameOverSystem(EntityManager *em, SystemManager *sm, Context *ctx, int player_id)
    : ISystem(em, sm), em_(*em), ctx_(*ctx), player_id_(player_id) {}

void GameOverSystem::OnUpdate() {
  auto player = em_.Get(player_id_);
  auto phc = player->Get<HealthComponent>();
  auto psc = player->Get<StepComponent>();
  if (phc->health_ <= 0) {
    ctx_.restart = true;
    ctx_.scene_ = "game_over";
  }
  if (psc->step_count_ > psc->max_steps_on_level_) {
    ctx_.restart = true;
    ctx_.scene_ = "game_over";
  }
}
