#include "./lib/ecs/component.h"

#ifndef INCLUDE_GAME_COMPONENTS_CONTROLCOMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_CONTROLCOMPONENT_H_

class ControlComponent : public IComponent {
 public:
  int up_btn_;
  int right_btn_;
  int down_btn_;
  int left_btn_;

  explicit ControlComponent(int up, int right, int down, int left)
      : up_btn_(up), right_btn_(right), down_btn_(down), left_btn_(left) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_CONTROLCOMPONENT_H_
