#include "../include/game/main.h"

int main() {
  terminal_open();
  terminal_set(
      "window: title='RogueLG', cellsize = 16x16, size = 63x43;"
      "font: /home/ruska/aksur/programming/roguelg/assets/fonts/jbm.ttf, size=15q");
  terminal_refresh();

  Controls controls;
  Context ctx{};
  SceneManager sm(ctx);

  sm.Put("title", new TitleScene(&ctx, controls));
  sm.Put("game", new GameScene(&ctx, controls));
  sm.Put("game_over", new GameOverScene(&ctx, controls));

  ctx.scene_ = "title";

  while (true) {
    terminal_clear();
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE) || controls.IsPressed(TK_ESCAPE)) {
      break;
    }
    sm.OnRender();
    controls.Reset();
    terminal_refresh();
  }
  sm.OnExit();
  terminal_close();
}
