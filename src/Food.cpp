#include "../include/Food.h"

Food::Food(int x, int y) : x_(x), y_(y) {}
// Food::Food() {}

int Food::GetX() const {
  return x_;
}

int Food::GetY() const {
  return y_;
}

char Food::GetSymbol() const {
  return symbol_;
}
