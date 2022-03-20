#include "../include/Player.h"

Player::Player(const Controls &controls, char symbol, int x, int y)
    : controls_(controls), symbol_(symbol), current_x_(x), current_y_(y) {}

int Player::GetX() const {
  return current_x_;
}

int Player::GetY() const {
  return current_y_;
}

void Player::Move() {
  if (controls_.IsLeft()) {
    current_x_ -= speed_;
    step_count_ += speed_;
  }
  if (controls_.IsUp()) {
    current_y_ -= speed_;
    step_count_ += speed_;
  }
  if (controls_.IsRight()) {
    current_x_ += speed_;
    step_count_ += speed_;
  }
  if (controls_.IsDown()) {
    current_y_ += speed_;
    step_count_ += speed_;
  }
}

void Player::Render() {
  terminal_put(current_x_, current_y_, symbol_);
  terminal_printf(1, 21, "Health: %d", current_health_);
  terminal_printf(1, 22, "Steps: %d", step_count_);
  terminal_printf(1, 23, "Coins: %d", current_coins_);
}

void Player::Update() {
  Move();
  Render();
}
