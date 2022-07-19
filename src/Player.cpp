#include "../include/Player.h"

Player::Player(const Controls &controls, char symbol, int x, int y)
    : controls_(controls), symbol_(symbol), current_x_(x), current_y_(y) {}

int Player::GetX() const {
  return current_x_;
}

int Player::GetY() const {
  return current_y_;
}

void Player::TakeCoin() {
  current_coins_++;
}

bool Player::IsHungry() {
  return current_food_ <= 0;
}

void Player::TakeFood(int food_sat) {
  if (current_food_ + food_sat < max_food_) {
    current_food_ += food_sat;
  } else if (current_food_ + food_sat >= max_food_) {
    current_food_ = max_food_;
  }
}

void Player::Move() {
  if (controls_.IsLeft() && !IsHungry()) {
    current_x_ -= speed_;
    step_count_ += speed_;
    current_food_--;
  }
  if (controls_.IsUp() && !IsHungry()) {
    current_y_ -= speed_;
    step_count_ += speed_;
    current_food_--;
  }
  if (controls_.IsRight() && !IsHungry()) {
    current_x_ += speed_;
    step_count_ += speed_;
    current_food_--;
  }
  if (controls_.IsDown() && !IsHungry()) {
    current_y_ += speed_;
    step_count_ += speed_;
    current_food_--;
  }
}

void Player::Render() {
  terminal_put(current_x_, current_y_, symbol_);

  terminal_printf(1, 28, "Health: %d", current_health_);
  terminal_printf(1, 29, "Food: %d", current_food_);
  terminal_printf(1, 30, "Coins: %d", current_coins_);
  terminal_printf(15, 28, "Steps: %d", step_count_);
  terminal_printf(15, 29, "X: %d", current_x_);
  terminal_printf(15, 30, "Y: %d", current_y_);
}

void Player::Update() {
  Move();
  Render();
}
