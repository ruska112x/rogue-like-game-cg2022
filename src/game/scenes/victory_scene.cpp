#include "../include/game/scenes/victory_scene.h"

VictoryScene::VictoryScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void VictoryScene::OnCreate() {}

void VictoryScene::OnRender() {
  terminal_clear();
  terminal_print(22, 12, "You are won!!!\nPress Enter to start");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "level0";
  }
  terminal_refresh();
}

void VictoryScene::OnExit() {}
