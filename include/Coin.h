#ifndef INCLUDE_COIN_H_
#define INCLUDE_COIN_H_

class Coin {
 private:
  char symbol_ = '$';
  int x_ = 0;
  int y_ = 0;

 public:
    Coin(int = 0, int = 0);
//  explicit Coin(int = 0, int = 0);

  int GetX() const;
  int GetY() const;
  char GetSymbol() const;
};

#endif  // INCLUDE_COIN_H_
