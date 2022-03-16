#include <BearLibTerminal.h>

#include "Controls.h"
#include "Obstacle.h"
#include "Player.h"
#include "Wall.h"

int main() {
    terminal_open();
    terminal_refresh();
    Wall wall('#', 80, 25);
    Controls controls;
    Player player(controls);

    while (!controls.IsExit()) {
        terminal_clear();

        controls.Update();
        wall.Update();
        player.Update();

        terminal_refresh();
    }
    terminal_close();
}