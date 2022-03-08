#include <BearLibTerminal.h>
#include <cmath>
#include <vector>

class Obstacle {
public:
  float x;
};

int to_pos(float x) { return static_cast<int>(std::round(x)); }

int main() {
  terminal_open();
  terminal_refresh();

  std::vector<Obstacle> obstacles{{20}, {50}, {70}};

  bool game_over = false;

  const int ground_y = 20;
  const int width = 80;

  float speed_x = 0.2;

  const float gravity = 0.1;
  float player_y = ground_y;
  int player_x = 1;

  const float max_jump = ground_y - 4;
  float speed_y = 0;
  const float max_speed_y = gravity * 3;

  while (true) {
    terminal_clear();

    if (terminal_has_input()) {
      auto event = terminal_read();
      if (event == TK_CLOSE) {
        break;
      }

      if (!game_over) {
        if (event == TK_SPACE && player_y >= ground_y) {
          speed_y = max_speed_y;
        }
      }
    }

    if (game_over) {
      terminal_print(35, 10, "GAME OVER!");
      terminal_refresh();
      continue;
    }

    for (int i = 0; i < width; i++) {
      terminal_put(i, ground_y + 1, '^');
    }

    player_y -= speed_y;
    player_y += gravity;

    if (player_y >= ground_y) {
      player_y = ground_y;
    }
    if (player_y <= max_jump) {
      speed_y = 0;
    }

    terminal_put(player_x, to_pos(player_y), '@');

    for (auto &o : obstacles) {
      o.x -= speed_x;
      if (o.x <= 0) {
        o.x = width;
      }

      if (player_x == to_pos(o.x) && to_pos(player_y) == to_pos(ground_y)) {
        terminal_printf(0, max_jump + 1, "Boom!");
        game_over = true;
      }
      terminal_put(to_pos(o.x), ground_y, '!');
    }
    terminal_refresh();
  }

  terminal_close();
}
