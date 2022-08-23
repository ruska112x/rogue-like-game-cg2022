#include "../include/game/scenes/title_scene.h"

TitleScene::TitleScene(Context* ctx, Controls* controls) : IScene(ctx), controls_(*controls) {}

void TitleScene::OnCreate() {
  x = 11;
  y = 8;
}

void TitleScene::OnRender() {
  terminal_clear();
  terminal_print(x, y, "@");
  terminal_print(12, 8, "Start game");
  terminal_print(12, 9, "Settings");
  terminal_print(12, 10, "Exit");
  if (controls_.IsPressed(TK_ENTER)) {
    if (y == 8) {
      if (!ctx_->random) {
        ctx_->scene_ = "level0";
      } else {
        ctx_->scene_ = "random";
      }
    }
    if (y == 9) {
      ctx_->scene_ = "settings";
    }
    if (y == 10) {
      ctx_->exit = true;
    }
  }
  if (controls_.IsPressed(TK_UP) && (y > 8)) {
    y -= 1;
  }
  if (controls_.IsPressed(TK_DOWN) && (y < 10)) {
    y += 1;
  }
  terminal_refresh();
}

void TitleScene::OnExit() {}
