#ifndef INCLUDE_ENTITYMANAGER_H_
#define INCLUDE_ENTITYMANAGER_H_

#include <vector>
#include <memory>

#include "./Coin.h"
#include "./Food.h"
#include "./Player.h"
#include "./Controls.h"
#include "./Wall.h"

#include "../include/LevelManager.h"

class EntityManager {
 private:
  Player &player_;
  Controls &controls_;
  Coin &coin_;
  Food &food_;
  Wall &wall_;
  LevelManager &lm_;

 public:
  std::vector<Coin> *coins_{};
  std::vector<Food> *foods_{};
  std::vector<Wall> *walls_{};

  EntityManager(Player *player, Controls *controls, Coin *coin, Food *food, Wall *wall, LevelManager *lm);

  void CoinUpdate();
  void FoodUpdate();
  void WallUpdate();
  void Update();
};

#endif  // INCLUDE_ENTITYMANAGER_H_
