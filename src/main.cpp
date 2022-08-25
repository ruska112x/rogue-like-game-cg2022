#include "../include/game/main.h"

#include <string>

// TODO: don't fix a bugs

int main() {
  terminal_open();
  terminal_set(
      "window: title='Crazy Cube Adventure', cellsize = 32x32, size = 33x23;"
      "font: assets/fonts/jbm.ttf, size=26");
  terminal_refresh();

  Controls controls;
  Context ctx{};
  SceneManager sm(ctx);

  ctx.player_health_ = 1000;
  ctx.player_steps_ = 0;
  ctx.player_max_steps_ = 128;
  ctx.player_damage_ = 100;

  sm.Put("title", new TitleScene(&ctx, &controls));
  sm.Put("settings", new SettingsScene(&ctx, &controls));
  sm.Put("level0", new GameScene(&ctx, controls, "assets/levels/00.txt", "title", "level1"));
  sm.Put("level1", new GameScene(&ctx, controls, "assets/levels/01.txt", "level0", "level2"));
  sm.Put("level2", new GameScene(&ctx, controls, "assets/levels/02.txt", "level1", "level3"));
  sm.Put("level3", new GameScene(&ctx, controls, "assets/levels/03.txt", "level2", "victory"));
  sm.Put("random", new RandomScene(&ctx, controls, "victory"));
  sm.Put("secret", new GameScene(&ctx, controls, "assets/levels/secret_room.txt", "victory", "game_over"));
  sm.Put("game_over", new GameOverScene(&ctx, controls));
  sm.Put("victory", new VictoryScene(&ctx, controls));

  ctx.scene_ = "title";

  while (!ctx.exit) {
    terminal_clear();
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE)) {
      break;
    }
    if (controls.IsPressed(TK_X) && (ctx.scene_ == "level0")) {
      ctx.scene_ = "level3";
    }
    if (controls.IsPressed(TK_S) && (ctx.scene_ == "settings")) {
      ctx.player_damage_ = 200;
      ctx.player_max_steps_ = 512;
      ctx.scene_ = "secret";
    }
    sm.OnRender();
    controls.Reset();
    terminal_refresh();
  }
  sm.OnExit();
  terminal_close();
}
