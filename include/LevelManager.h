#ifndef INCLUDE_LEVELMANAGER_H_
#define INCLUDE_LEVELMANAGER_H_

#include <vector>
#include <string>

#include "./Coin.h"
#include "./Food.h"
#include "./Player.h"
#include "./Wall.h"

class LevelManager {
 private:
  Player &player_;
  Coin &coin_;
  Food &food_;
  Wall &wall_;

 public:
  LevelManager(Player *player, Coin *coin, Food *food, Wall *wall);

  void GetLevel(std::string name);

  std::vector<Coin> coins_;
  std::vector<Food> foods_;
  std::vector<Wall> walls_;
};

#endif  // INCLUDE_LEVELMANAGER_H_
