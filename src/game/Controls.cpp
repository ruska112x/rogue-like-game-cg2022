#include "../include/game/Controls.h"

int Controls::GetKey() {
  while (terminal_has_input()) {
    return  terminal_read();
  }
}
