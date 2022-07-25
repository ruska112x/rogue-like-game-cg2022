#ifndef INCLUDE_CONTROLS_H_
#define INCLUDE_CONTROLS_H_

#include <BearLibTerminal.h>

class Controls {
 private:
  bool is_exit_ = false;

  bool left_ = false;
  bool up_ = false;
  bool right_ = false;
  bool down_ = false;

 public:
  bool IsExit() const;

  bool IsLeft() const;

  bool IsUp() const;

  bool IsRight() const;

  bool IsDown() const;

  void SetLeft(bool v);
  void SetUp(bool v);
  void SetRight(bool v);
  void SetDown(bool v);

  void Update();
};

#endif  // INCLUDE_CONTROLS_H_
