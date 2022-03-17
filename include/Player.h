#pragma once
#include <BearLibTerminal.h>

#include "Controls.h"

class Player {
   private:
    char symbol_ = '@';
    int current_x_ = 20;
    int current_y_ = 12;
    int speed_ = 1;

    const Controls &controls_;

    void Render() { terminal_put(current_x_, current_y_, symbol_); }

    void Move() {
        if (controls_.IsLeft()) {
            current_x_ -= speed_;
        }
        if (controls_.IsUp()) {
            current_y_ -= speed_;
        }
        if (controls_.IsRight()) {
            current_x_ += speed_;
        }
        if (controls_.IsDown()) {
            current_y_ += speed_;
        }
    }

   public:
    Player(const Controls &controls) : controls_(controls) {}

    void Update() {
        Move();
        Render();
    }
};