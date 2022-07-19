#ifndef INCLUDE_FOOD_H_
#define INCLUDE_FOOD_H_

class Food {
 private:
  char symbol_ = '%';
  int x_ = 0;
  int y_ = 0;

 public:
    Food(int = 0, int = 0);
//  explicit Food(int = 0, int = 0);

  int sat_ = 16;

  int GetX() const;
  int GetY() const;
  char GetSymbol() const;
};

#endif  // INCLUDE_FOOD_H_
