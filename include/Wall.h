#ifndef INCLUDE_WALL_H_
#define INCLUDE_WALL_H_

class Wall {
 private:
  char symbol_ = '#';
  int x_ = 0;
  int y_ = 0;

 public:
  Wall(int = 0, int = 0);

  int GetX() const;
  int GetY() const;
  char GetSymbol() const;
};

#endif  // INCLUDE_WALL_H_
