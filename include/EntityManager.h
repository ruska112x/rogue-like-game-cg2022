#ifndef INCLUDE_ENTITYMANAGER_H_
#define INCLUDE_ENTITYMANAGER_H_

#include <vector>
#include <memory>

#include "./Coin.h"
#include "./Food.h"
#include "./Player.h"

class EntityManager {
 private:
  Player &player_;
  Coin &coin_;
  Food &food_;

 public:
  std::vector<Coin> coins_{};
  std::vector<Food> foods_{};

  EntityManager(Player *player, Coin *coin, Food *food);

  void CoinUpdate();
  void FoodUpdate();
  void Update();
};

#endif  // INCLUDE_ENTITYMANAGER_H_
