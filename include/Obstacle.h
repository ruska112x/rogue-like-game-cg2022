#pragma once
#include <BearLibTerminal.h>

class Obstacle {
   private:
    char symbol_;

   public:
    int x_;
    int y_;

    Obstacle(int x, int y, char symbol) : x_(x), y_(y), symbol_(symbol) {}

    void Update() { terminal_put(x_, y_, symbol_); }
};