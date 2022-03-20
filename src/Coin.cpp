#include "../include/Coin.h"

Coin::Coin(int x, int y) : x_(x), y_(y) {}

int Coin::GetX() const {
  return x_;
}

int Coin::GetY() const {
  return y_;
}

void Coin::Update() {
  terminal_put(x_, y_, symbol_);
}
