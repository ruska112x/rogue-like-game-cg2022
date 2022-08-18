#include "../include/game/scenes/game_over_scene.h"

GameOverScene::GameOverScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void GameOverScene::OnCreate() {}

void GameOverScene::OnRender() {
  terminal_clear();
  terminal_print(4, 4, "Game Over\nPress Enter to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "title";
  }
  terminal_refresh();
}

void GameOverScene::OnExit() {}