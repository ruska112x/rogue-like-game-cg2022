#include <BearLibTerminal.h>
#include "./Coin.h"

#include "./Controls.h"
#include "./EntityManager.h"
#include "./LevelManager.h"

int main() {
  terminal_open();
  terminal_set("window: title='RogueLG', size = 64x32; font: ./assets/fonts/jbm.ttf, size=16");
  terminal_refresh();
  Controls controls;
  Player player(controls, '@', 1, 1);
  Coin coin;
  Food food;
  Wall wall;
  LevelManager lm(&player, &coin, &food, &wall);
  EntityManager em(&player, &controls, &coin, &food, &wall, &lm);

  lm.GetLevel("/home/ruska/aksur/programming/roguelg_4/assets/levels/00.txt");


  while (!controls.IsExit()) {
    terminal_clear();

    controls.Update();
    em.Update();
    player.Update();

    if (player.IsHungry()) {
      terminal_clear();
      terminal_printf(27, 15, "GAME OVER!");
      terminal_refresh();
    }

    terminal_refresh();
  }

  terminal_close();
}
