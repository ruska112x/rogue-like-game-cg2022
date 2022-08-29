#include "../include/game/systems/cheat_system.h"

CheatSystem::CheatSystem(EntityManager *em, SystemManager *sm, const Controls &controls, Context *ctx)
    : ISystem(em, sm), controls_(controls), ctx_(*ctx) {}

void CheatSystem::OnUpdate() {
  if (controls_.IsPressed(TK_X) && (ctx_.scene_ == "level0")) {
    ctx_.scene_ = "level3";
  }
  if (controls_.IsPressed(TK_S) && (ctx_.scene_ == "settings")) {
    ctx_.p_damage_ = 200;
    ctx_.p_max_steps_ = 512;
    ctx_.scene_ = "secret";
  }
}
