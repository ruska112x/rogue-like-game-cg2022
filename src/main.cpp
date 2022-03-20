#include <BearLibTerminal.h>

#include "../include/Coin.h"
#include "../include/Controls.h"
#include "../include/Player.h"

int main() {
  terminal_open();
  terminal_refresh();
  Controls controls;
  Player player(controls, '@', 4, 4);
  Coin coin(0, 0);

  while (!controls.IsExit()) {
    terminal_clear();

    controls.Update();
    player.Update();
    coin.Update();

    terminal_refresh();
  }
  terminal_close();
}
