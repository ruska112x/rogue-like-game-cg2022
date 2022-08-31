#ifndef INCLUDE_GAME_COMPONENTS_MORE_STEPS_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_MORE_STEPS_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class MoreStepsComponent : public IComponent {
 public:
  int more_steps_;

  explicit MoreStepsComponent(int more_steps) : more_steps_(more_steps) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_MORE_STEPS_COMPONENT_H_
