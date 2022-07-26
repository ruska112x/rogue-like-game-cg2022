#include "../include/LevelManager.h"

#include <fstream>
#include <string>

LevelManager::LevelManager(Player *player, Coin *coin, Food *food, Wall *wall)
    : player_(*player), coin_(*coin), food_(*food), wall_(*wall) {}

void LevelManager::GetLevel(std::string name) {
  std::ifstream fin;
  fin.open(name);
  char symbol;
  while (!fin.eof()) {
    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 64; j++) {
        fin >> symbol;
        //        if (symbol == player_.GetSymbol()) {
        //          player_.SetX(j);
        //          player_.SetY(i);
        //        }
        if (symbol == '$') {
          coins_.push_back({j, i});
        }
        if (symbol == '%') {
          foods_.push_back({j, i});
        }
        if (symbol == '#') {
          walls_.push_back({j, i});
        }
      }
    }
  }
}
