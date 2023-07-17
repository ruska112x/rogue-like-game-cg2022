#include "../include/game/main.h"

// TODO: don't fix a bugs

int main() {
  terminal_open();
  terminal_set(
      "window: title='Chin-Chan-Chon-Chin', cellsize = 32x32, size = 33x23;"
      "font: assets/fonts/jbm.ttf, size=26");
  terminal_refresh();

  Controls controls;
  Context ctx{};
  SceneManager sm(ctx);

  ctx.p_health_ = 1000;
  ctx.p_steps_ = 0;
  ctx.p_max_steps_ = 448;
  ctx.p_damage_ = 100;
  ctx.p_credits_ = 100;

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
    sm.OnRender();
    controls.Reset();
    terminal_refresh();
  }
  sm.OnExit();
  terminal_close();
}
