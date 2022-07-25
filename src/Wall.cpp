#include "../include/Wall.h"

Wall::Wall(int x, int y) : x_(x), y_(y) {}

int Wall::GetX() const {
  return x_;
}

int Wall::GetY() const {
  return y_;
}

char Wall::GetSymbol() const {
  return symbol_;
}
