#ifndef INCLUDE_GAME_COMPONENTS_STEP_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_STEP_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class StepComponent : public IComponent {
 public:
  int step_count_ = 0;
};

#endif  // INCLUDE_GAME_COMPONENTS_STEP_COMPONENT_H_
