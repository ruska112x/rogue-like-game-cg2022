#include "../include/game/scenes/title_scene.h"

TitleScene::TitleScene(Context *ctx, const Controls &controls) : IScene(ctx), controls_(controls) {}

void TitleScene::OnCreate() {}

void TitleScene::OnRender() {
  terminal_clear();
  terminal_print(22, 12, "ruska's GAME\nPress Enter to start");
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "level0";
  }
  terminal_refresh();
}

void TitleScene::OnExit() {}
