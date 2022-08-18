#ifndef INCLUDE_GAME_LEVEL_MANAGER_H_
#define INCLUDE_GAME_LEVEL_MANAGER_H_

#include <fstream>
#include <string>
#include <vector>

#include "../include/lib/math/vec2.h"

class LevelManager {
 public:
  Vec2 player_pos_;
  std::vector<Vec2> walls_pos_;
  std::vector<Vec2> food_pos_;
  void GetLevel(std::string name) {
    std::ifstream fin;
    fin.open(name);
    char symbol;
    int i = 0, j = 0;
    while (!fin.eof()) {
      fin.get(symbol);
      if (symbol == '@') {
        player_pos_.x = static_cast<float>(i);
        player_pos_.y = static_cast<float>(j);
      }
      if (symbol == '#') {
        walls_pos_.emplace_back(Vec2(i, j));
      }
      if (symbol == '%') {
        food_pos_.emplace_back(Vec2(i, j));
      }
      i++;
      if (symbol == '\n') {
        j++;
        i = 0;
      }
      symbol = ' ';
    }
  }
};

#endif  // INCLUDE_GAME_LEVEL_MANAGER_H_
