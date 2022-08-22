#ifndef INCLUDE_GAME_COMPONENTS_STEP_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_STEP_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class StepComponent : public IComponent {
 public:
  int step_count_ = 0;
  int max_steps_on_level_ = 0;

  explicit StepComponent(int max_steps_on_level) : max_steps_on_level_(max_steps_on_level) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_STEP_COMPONENT_H_
