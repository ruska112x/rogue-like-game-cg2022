#ifndef INCLUDE_GAME_COMPONENTS_OPEN_DOOR_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_OPEN_DOOR_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class OpenDoorComponent : public IComponent {
 public:
  bool is_open_ = false;
};

#endif  // INCLUDE_GAME_COMPONENTS_OPEN_DOOR_COMPONENT_H_
