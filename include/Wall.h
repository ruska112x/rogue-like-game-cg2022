#pragma once
#include <BearLibTerminal.h>

class Wall {
   private:
    char symbol_;
    int width_;
    int height_;

   public:
    Wall(char symbol, int width, int height)
        : symbol_(symbol), width_(width), height_(height) {}

    void Update() {
        int i, j;
        for (i = 0; i < width_; i++) {
            terminal_put(i, 0, symbol_);
        }
        for (j = 0; j < height_; j++) {
            terminal_put(width_ - 1, j, symbol_);
        }
        for (i = 0; i < width_; i++) {
            terminal_put(i, height_ - 1, symbol_);
        }
        for (j = 0; j < height_; j++) {
            terminal_put(0, j, symbol_);
        }
    }
};