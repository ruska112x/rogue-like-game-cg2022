#include "../include/game/scenes/game_over_scene.h"

GameOverScene::GameOverScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void GameOverScene::OnCreate() {
  terminal_set("0x23: none; 0x3e: none; 0x3c: none; 0x25: none; 0x45: none; 0x40: none; 0x2d: none");
  terminal_set("0x5b: assets/sprites/good.png; 0x5d: assets/sprites/bad.png");
}

void GameOverScene::OnRender() {
  terminal_clear();
  terminal_printf(6, 6, "Game Over");
  ctx_->p_credits_ = -1000000;
  if (ctx_->p_credits_ > 0) {
    terminal_printf(6, 7, "+%d Social Credit", ctx_->p_credits_);
    terminal_put(30, 6, 0x5b);
  } else {
    terminal_printf(6, 7, "%d Social Credit", ctx_->p_credits_);
    terminal_put(30, 6, 0x5d);
  }
  terminal_printf(6, 8, "Press ENTER to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->restart = true;
    ctx_->scene_ = "title";
  }
  terminal_refresh();
}

void GameOverScene::OnExit() {}
