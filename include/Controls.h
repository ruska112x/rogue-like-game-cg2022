#pragma once
#include <BearLibTerminal.h>

class Controls {
   private:
    bool is_exit_ = false;

    bool left_ = false;
    bool up_ = false;
    bool right_ = false;
    bool down_ = false;

   public:
    bool IsExit() const { return is_exit_; }

    bool IsLeft() const { return left_; };
    bool IsUp() const { return up_; };
    bool IsRight() const { return right_; };
    bool IsDown() const { return down_; };

    void Update() {
        if (!is_exit_) {
            left_ = false;
            up_ = false;
            right_ = false;
            down_ = false;

            is_exit_ = false;

            while (terminal_has_input()) {
                auto key = terminal_read();

                bool left_key = key == TK_A || key == TK_LEFT;
                bool up_key = key == TK_W || key == TK_UP;
                bool right_key = key == TK_D || key == TK_RIGHT;
                bool down_key = key == TK_S || key == TK_DOWN;

                if (key == TK_CLOSE) {
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
};