#ifndef INCLUDE_GAME_LEVEL_MANAGER_H_
#define INCLUDE_GAME_LEVEL_MANAGER_H_

#include <fstream>
#include <random>
#include <string>
#include <vector>

#include "../include/lib/math/vec2.h"
#include "../include/lib/scenes/context.h"

class LevelManager {
 public:
  Vec2 player_pos_;
  Vec2 prev_door_pos_;
  Vec2 next_door_pos_;
  Vec2 key_pos_;
  std::vector<Vec2> enemy_pos_;
  std::vector<Vec2> walls_pos_;
  std::vector<Vec2> food_pos_;

  static int rand_int(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    return static_cast<int>(dist(rng));
  }

  void GetRandomLevel() {
    player_pos_ = ZeroVec2;
    prev_door_pos_ = ZeroVec2;
    next_door_pos_ = ZeroVec2;
    while (!enemy_pos_.empty()) {
      enemy_pos_.pop_back();
    }
    while (!walls_pos_.empty()) {
      walls_pos_.pop_back();
    }
    while (!food_pos_.empty()) {
      food_pos_.pop_back();
    }
    int i = 2, j = 1;
    player_pos_ = OnesVec2;
    for (int k = 0; k < 33; ++k) {
      walls_pos_.emplace_back(Vec2(k, 0));
      walls_pos_.emplace_back(Vec2(k, 15));
    }
    for (int k = 1; k < 15; ++k) {
      walls_pos_.emplace_back(Vec2(0, k));
      walls_pos_.emplace_back(32, k);
    }
    walls_pos_.pop_back();
    next_door_pos_ = Vec2(32, 14);

    for (j = 2; j < 14; ++j) {
      for (i = 1; i < 32; ++i) {
        int rand_key = rand_int(0, 100);
        if (rand_key == 1) {
          enemy_pos_.emplace_back(i, j);
        }
        if ((rand_key >= 10) && (rand_key <= 30)) {
          walls_pos_.emplace_back(i, j);
        }
        if ((rand_key >= 50) && (rand_key <= 60)) {
          food_pos_.emplace_back(i, j);
        }
      }
    }
  }

  void GetLevel(std::string name) {
    player_pos_ = ZeroVec2;
    prev_door_pos_ = ZeroVec2;
    next_door_pos_ = ZeroVec2;
    while (!enemy_pos_.empty()) {
      enemy_pos_.pop_back();
    }
    while (!walls_pos_.empty()) {
      walls_pos_.pop_back();
    }
    while (!food_pos_.empty()) {
      food_pos_.pop_back();
    }
    std::ifstream fin;
    fin.open(name);
    char symbol;
    int i = 0, j = 0;
    while (!fin.eof()) {
      fin.get(symbol);
      if (symbol == '@') {
        player_pos_ = Vec2(i, j);
      }
      if (symbol == '<') {
        prev_door_pos_ = Vec2(i, j);
      }
      if (symbol == '>') {
        next_door_pos_ = Vec2(i, j);
      }
      if (symbol == 'E') {
        enemy_pos_.emplace_back(Vec2(i, j));
      }
      if (symbol == '#') {
        walls_pos_.emplace_back(Vec2(i, j));
      }
      if (symbol == '%') {
        food_pos_.emplace_back(Vec2(i, j));
      }
      if (symbol == '-') {
        key_pos_ = Vec2(i, j);
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
