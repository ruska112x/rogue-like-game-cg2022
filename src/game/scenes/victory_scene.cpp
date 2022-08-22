#include "../include/game/scenes/victory_scene.h"

VictoryScene::VictoryScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void VictoryScene::OnCreate() {}

void VictoryScene::OnRender() {
  terminal_clear();
  terminal_print(7, 6, "You won!!!\nPress Enter to go to main menu");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "level0";
    ctx_->restart = false;
  }
  terminal_refresh();
}

void VictoryScene::OnExit() {}
