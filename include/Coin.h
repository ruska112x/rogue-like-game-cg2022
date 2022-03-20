#ifndef INCLUDE_COIN_H_
#define INCLUDE_COIN_H_

#include <BearLibTerminal.h>

class Coin {
 private:
  char symbol_ = '$';

 public:
  int x_;
  int y_;

  Coin(int x, int y);

  int GetX() const;
  int GetY() const;

  void Update();
};

#endif  // INCLUDE_COIN_H_
