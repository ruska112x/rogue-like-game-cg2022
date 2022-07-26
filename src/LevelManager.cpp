#include "../include/LevelManager.h"

#include <fstream>
#include <string>

LevelManager::LevelManager(Player *player, Coin *coin, Food *food, Wall *wall)
    : player_(*player), coin_(*coin), food_(*food), wall_(*wall) {}

void LevelManager::GetLevel(std::string name) {
  std::ifstream fin;
  fin  >> std::noskipws;
  fin.open(name);
  char symbol;
  int i = 0, j = 0;
  while (!fin.eof()) {
    fin >> symbol;
    if (symbol == player_.GetSymbol()) {
      player_.SetX(j);
      player_.SetY(i);
    }
    if (symbol == '$') {
      coins_.emplace_back(j, i);
    }
    if (symbol == '%') {
      foods_.emplace_back(j, i);
    }
    if (symbol == '#') {
      walls_.emplace_back(j, i);
    }

    j++;
    if (symbol == '\n') {
      i++;
      j = 0;
    }
    symbol = ' ';
  }
}
