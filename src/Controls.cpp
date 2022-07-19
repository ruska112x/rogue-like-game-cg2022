#include "../include/Controls.h"

bool Controls::IsExit() const {
  return is_exit_;
}

bool Controls::IsLeft() const {
  return left_;
}

bool Controls::IsUp() const {
  return up_;
}

bool Controls::IsRight() const {
  return right_;
}

bool Controls::IsDown() const {
  return down_;
}

void Controls::Update() {
  if (!is_exit_) {
    left_ = false;
    up_ = false;
    right_ = false;
    down_ = false;

    is_exit_ = false;

    while (terminal_has_input()) {
      auto key = terminal_read();

      bool exit_key = key == TK_CLOSE || key == TK_ESCAPE;
      bool left_key = key == TK_A || key == TK_LEFT;
      bool up_key = key == TK_W || key == TK_UP;
      bool right_key = key == TK_D || key == TK_RIGHT;
      bool down_key = key == TK_S || key == TK_DOWN;

      if (exit_key) {
        is_exit_ = true;
      }
      if (left_key) {
        left_ = true;
      }
      if (up_key) {
        up_ = true;
      }
      if (right_key) {
        right_ = true;
      }
      if (down_key) {
        down_ = true;
      }
    }
  }
}
