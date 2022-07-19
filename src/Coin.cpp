#include "../include/Coin.h"

Coin::Coin(int x, int y) : x_(x), y_(y) {}

// Coin::Coin() {}

int Coin::GetX() const {
  return x_;
}

int Coin::GetY() const {
  return y_;
}

char Coin::GetSymbol() const {
  return symbol_;
}
