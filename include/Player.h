#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <BearLibTerminal.h>

#include "./Controls.h"

class Player {
 private:
  char symbol_ = '@';
  int current_x_ = 1;
  int current_y_ = 1;
  const int speed_ = 1;

  int step_count_ = 0;
  int current_coins_ = 0;

  const int max_health_ = 128;
  int current_health_ = 100;

  int current_food_ = 16;
  const int max_food_ = 128;

  const Controls &controls_;

  void Move();

  void Render();

 public:
  Player(const Controls &controls, char symbol, int x, int y);

  int GetX() const;
  int GetY() const;

  char GetSymbol();

  void SetX(int x);
  void SetY(int y);

  void TakeCoin();

  void TakeFood(int food_sat);
  bool IsHungry();

  void Update();
};

#endif  // INCLUDE_PLAYER_H_
