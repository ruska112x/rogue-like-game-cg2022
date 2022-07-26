#include "../include/EntityManager.h"

#include <./BearLibTerminal.h>

EntityManager::EntityManager(Player *player, Controls *controls, Coin *coin, Food *food, Wall *wall, LevelManager *lm)
    : player_(*player), controls_(*controls), coin_(*coin), food_(*food), wall_(*wall), lm_(*lm) {
  coins_ = lm_.coins_;
  foods_ = lm_.foods_;
  walls_ = lm_.walls_;
}

void EntityManager::CoinUpdate() {
  for (int i = 0; i < coins_.size(); i++) {
    terminal_color(color_from_name("green"));
    terminal_put(coins_[i].GetX(), coins_[i].GetY(), coins_[i].GetSymbol());
    terminal_color(color_from_name("white"));
    if ((coins_[i].GetX() == player_.GetX()) && (coins_[i].GetY() == player_.GetY())) {
      player_.TakeCoin();
      coins_.erase(coins_.begin() + i);
    }
  }
}

void EntityManager::FoodUpdate() {
  for (int i = 0; i < foods_.size(); i++) {
    terminal_color(color_from_name("red"));
    terminal_put(foods_[i].GetX(), foods_[i].GetY(), foods_[i].GetSymbol());
    terminal_color(color_from_name("white"));
    if ((foods_[i].GetX() == player_.GetX()) && (foods_[i].GetY() == player_.GetY())) {
      player_.TakeFood(food_.sat_);
      foods_.erase(foods_.begin() + i);
    }
  }
}

void EntityManager::WallUpdate() {
  for (int i = 0; i < walls_.size(); i++) {
    terminal_put(walls_[i].GetX(), walls_[i].GetY(), walls_[i].GetSymbol());
    if (controls_.IsLeft()) {
      if (player_.GetX() - 1 == walls_[i].GetX() && player_.GetY() == walls_[i].GetY()) {
        controls_.SetLeft(false);
      }
    }
    if (controls_.IsRight()) {
      if (player_.GetX() + 1 == walls_[i].GetX() && player_.GetY() == walls_[i].GetY()) {
        controls_.SetRight(false);
      }
    }
    if (controls_.IsUp()) {
      if (player_.GetY() - 1 == walls_[i].GetY() && player_.GetX() == walls_[i].GetX()) {
        controls_.SetUp(false);
      }
    }
    if (controls_.IsDown()) {
      if (player_.GetY() + 1 == walls_[i].GetY() && player_.GetX() == walls_[i].GetX()) {
        controls_.SetDown(false);
      }
    }
  }
}

void EntityManager::Update() {
  CoinUpdate();
  FoodUpdate();
  WallUpdate();
}
