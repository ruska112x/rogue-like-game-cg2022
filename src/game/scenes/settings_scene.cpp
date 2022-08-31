#include "../include/game/scenes/settings_scene.h"

SettingsScene::SettingsScene(Context *ctx, Controls *controls)
    : IScene(ctx),
      controls_(*controls),
      x(9),
      y(8),
      rand_accept('-'),
      prepare_accept('+'),
      ascii_accept('+'),
      sprite_accept('-') {}

void SettingsScene::OnCreate() {
  if (ctx_->sprite) {
    ascii_accept = '-';
    sprite_accept = '+';
  } else {
    ascii_accept = '+';
    sprite_accept = '-';
  }
  if (ctx_->random) {
    rand_accept = '+';
    prepare_accept = '-';
  } else {
    rand_accept = '-';
    prepare_accept = '+';
  }
  auto systemManager = engine.GetSystemManager();
  systemManager->AddSystem<CheatSystem>(controls_, ctx_);
}

void SettingsScene::OnRender() {
  engine.OnUpdate();
  terminal_clear();
  terminal_print(x, y, ">");
  terminal_print(10, 8, "Graphics:");
  terminal_printf(11, 9, "%c", ascii_accept);
  terminal_print(12, 9, "ascii");
  terminal_printf(11, 10, "%c", sprite_accept);
  terminal_print(12, 10, "sprite");
  terminal_print(10, 11, "Random level:");
  terminal_printf(11, 12, "%c", rand_accept);
  terminal_print(12, 12, "random");
  terminal_printf(11, 13, "%c", prepare_accept);
  terminal_print(12, 13, "prepare");
  terminal_print(12, 14, "Exit");
  if (controls_.IsPressed(TK_ENTER)) {
    if (y == 9) {
      ctx_->sprite = false;
      ascii_accept = '+';
      sprite_accept = '-';
    }
    if (y == 10) {
      ctx_->sprite = true;
      ascii_accept = '-';
      sprite_accept = '+';
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
  if (controls_.IsPressed(TK_UP)) {
    y -= 1;
    if (y == 7) {
      y = 14;
    }
  }
  if (controls_.IsPressed(TK_DOWN)) {
    y += 1;
    if (y == 15) {
      y = 8;
    }
  }
  if (controls_.IsPressed(TK_ESCAPE)) {
    ctx_->scene_ = "title";
  }
  terminal_refresh();
}

void SettingsScene::OnExit() {}
