#pragma once
#include "controls.h"

class Player {
   private:
    char symbol_ = '@';
    int pos_x_;
    int pos_y_;
    int speed_;
    int steps_count_;

    const Controls &controls_;

    void Render();

    void Move();

   public:
    Player(const Controls &controls, char symbol, int x, int y, int speed)
        : Controls_(controls),
          symbol_(symbol),
          pos_x_(x),
          pos_y_(y),
          speed_(speed) {}
};