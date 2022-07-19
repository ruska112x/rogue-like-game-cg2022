#include <../include/Coin.h>
#include <BearLibTerminal.h>

#include "../include/Controls.h"
#include "../include/EntityManager.h"

int main() {
  terminal_open();
  terminal_set("window: title='RogueLG', size = 128x32; font: ./assets/fonts/jbm.ttf, size=13");
  terminal_refresh();
  Controls controls;
  Player player(controls, '@', 1, 1);
  Coin coin;
  Food food;
  EntityManager em(&player, &coin, &food);

  while (!controls.IsExit()) {
    terminal_clear();

    controls.Update();
    player.Update();
    em.Update();

    if (player.IsHungry()) {
      terminal_clear();
      terminal_printf(59, 15, "GAME OVER!");
      terminal_refresh();
    }

    terminal_refresh();
  }

  terminal_close();
}
