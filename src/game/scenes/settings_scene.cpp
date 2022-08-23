#include "../include/game/scenes/settings_scene.h"

SettingsScene::SettingsScene(Context *ctx, Controls *controls)
    : IScene(ctx),
      controls_(*controls),
      x(9),
      y(8),
      rand_accept('-'),
      prepare_accept('+'),
      ascii_accept('+'),
      tile_accept('-') {}

void SettingsScene::OnCreate() {}

void SettingsScene::OnRender() {
  terminal_clear();
  terminal_print(x, y, "@");
  terminal_print(10, 8, "Graphics:");
  terminal_printf(11, 9, "%c", ascii_accept);
  terminal_print(12, 9, "ascii");
  terminal_printf(11, 10, "%c", tile_accept);
  terminal_print(12, 10, "tile");
  terminal_print(10, 11, "Random level:");
  terminal_printf(11, 12, "%c", rand_accept);
  terminal_print(12, 12, "random");
  terminal_printf(11, 13, "%c", prepare_accept);
  terminal_print(12, 13, "prepare");
  terminal_print(12, 14, "Exit");
  if (controls_.IsPressed(TK_ENTER)) {
    if (y == 9) {
      ctx_->tile = false;
      ascii_accept = '+';
      tile_accept = '-';
    }
    if (y == 10) {
      ctx_->tile = true;
      ascii_accept = '-';
      tile_accept = '+';
    }
    if (y == 12) {
      ctx_->random = true;
      rand_accept = '+';
      prepare_accept = '-';
    }
    if (y == 13) {
      ctx_->random = false;
      rand_accept = '-';
      prepare_accept = '+';
    }
    if (y == 14) {
      ctx_->scene_ = "title";
    }
  }
  if (controls_.IsPressed(TK_UP) && (y > 8)) {
    y -= 1;
  }
  if (controls_.IsPressed(TK_DOWN) && (y < 14)) {
    y += 1;
  }
  terminal_refresh();
}

void SettingsScene::OnExit() {}
