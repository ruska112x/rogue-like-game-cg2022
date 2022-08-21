#include "../include/game/main.h"

#include <string>

int main() {
  terminal_open();
  terminal_set(
      "window: title='RogueLG', cellsize = 16x16, size = 63x43;"
      "font: /home/ruska/aksur/programming/roguelg/assets/fonts/jbm.ttf, size=15");
  terminal_refresh();

  Controls controls;
  Context ctx{};
  SceneManager sm(ctx);

  std::string level_names_[] = {"/home/ruska/aksur/programming/roguelg/assets/levels/00.txt",
                                "/home/ruska/aksur/programming/roguelg/assets/levels/01.txt",
                                "/home/ruska/aksur/programming/roguelg/assets/levels/02.txt",
                                "/home/ruska/aksur/programming/roguelg/assets/levels/03.txt"};

  sm.Put("title", new TitleScene(&ctx, controls));
  sm.Put("level0", new GameScene(&ctx, controls, level_names_[0]));
  sm.Put("level1", new GameScene(&ctx, controls, level_names_[1]));
  sm.Put("level2", new GameScene(&ctx, controls, level_names_[2]));
  sm.Put("level3", new GameScene(&ctx, controls, level_names_[3]));
  sm.Put("game_over", new GameOverScene(&ctx, controls));
  sm.Put("victory", new VictoryScene(&ctx, controls));

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
