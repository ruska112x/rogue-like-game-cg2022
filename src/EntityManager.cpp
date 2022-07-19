#include <./BearLibTerminal.h>

#include "../include/EntityManager.h"

EntityManager::EntityManager(Player *player, Coin *coin, Food *food) : player_(*player), coin_(*coin), food_(*food) {
    coins_ = {{99, 1}, {3, 1}, {5, 1}, {7, 1}, {9, 1}};
    foods_ = {{2, 2}, {4, 2}, {6, 2}, {12, 5}, {17, 15}, {23, 4}, {45, 2}};
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

void EntityManager::Update() {
  CoinUpdate();
  FoodUpdate();
}
