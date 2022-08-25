#include "../include/game/scenes/game_over_scene.h"

GameOverScene::GameOverScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void GameOverScene::OnCreate() {
  terminal_set("0x23: none; 0x3e: none; 0x3c: none; 0x25: none; 0x45: none; 0x40: none; 0x2d: none");
}

void GameOverScene::OnRender() {
  terminal_clear();
  terminal_print(7, 6, "Game Over\nPress ENTER to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->restart = true;
    ctx_->scene_ = "title";
  }
  terminal_refresh();
}

void GameOverScene::OnExit() {}
