#ifndef INCLUDE_GAME_COMPONENTS_CONTROL_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_CONTROL_COMPONENT_H_

#include <BearLibTerminal.h>

#include "../include/lib/ecs/component.h"

class ControlComponent : public IComponent {
 public:
  int btn_left_;
  int btn_up_;
  int btn_right_;
  int btn_down_;

  bool left_pressed_ = false;
  bool up_pressed_ = false;
  bool right_pressed_ = false;
  bool down_pressed_ = false;

  explicit ControlComponent(int btn_left, int btn_up, int btn_right, int btn_down)
      : btn_left_(btn_left), btn_up_(btn_up), btn_right_(btn_right), btn_down_(btn_down) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_CONTROL_COMPONENT_H_
