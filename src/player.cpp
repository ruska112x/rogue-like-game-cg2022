#include "player.h"
#include <BearLibTerminal.h>

Player::Render() { terminal_put(pos_x_, pos_y_, symbol_); }

Player::SetLeft()

Player::Move() {
    if (left_) {
        pos_x_ -= speed_;
        steps_count_++;
    }
    if (up_) {
        pos_y_ -= speed_;
        steps_count_++;
    }
    if (right_) {
        pos_x_ += speed_;
        steps_count_++;
    }
    if (down_) {
        pos_y_ += speed_;
        steps_count_++;
    }
}