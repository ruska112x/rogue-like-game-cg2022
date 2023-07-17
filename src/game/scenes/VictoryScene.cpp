#include "game/scenes/VictoryScene.h"

VictoryScene::VictoryScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void VictoryScene::OnCreate() {
  terminal_set("0x5b: assets/sprites/good.png; 0x5d: assets/sprites/bad.png");
}

void VictoryScene::OnRender() {
  terminal_clear();
  terminal_print(7, 6, "You won!!!");
  if (ctx_->p_credits_ > 0) {
    terminal_printf(7, 7, "+%d Social Credit", ctx_->p_credits_);
    terminal_put(27, 6, 0x5b);
  } else {
    terminal_printf(7, 6, "%d Social Credit", ctx_->p_credits_);
    terminal_put(27, 7, 0x5d);
  }
  terminal_printf(7, 8, "Press ENTER to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->restart = true;
    ctx_->scene_ = "title";
  }
  terminal_refresh();
}

void VictoryScene::OnExit() {}
