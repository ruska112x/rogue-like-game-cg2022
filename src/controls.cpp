#include "controls.h"
#include <BearLibTerminal.h>

Controls::IsExit() const { return is_exit_; }
Controls::SetOver(bool exit) { is_over_ = exit; }
Controls::IsOver() const { return is_over_; }

Controls::Update() {
    if (!is_over_ && !is_exit_) {
        while (terminal_has_input()) {
            auto key = terminal_read();
            if (key == TK_A) {
                left = 
            }
            if (key == TK_W) {

            }
            if (key == TK_D) {

            }
            if (key == TK_S) {

            }
        }
    }
}