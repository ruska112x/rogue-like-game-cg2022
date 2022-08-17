#ifndef INCLUDE_GAME_COMPONENTS_COLLISION_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_COLLISION_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class CollisionComponent : public IComponent {
 public:
  bool left_ = false;
  bool up_ = false;
  bool right_ = false;
  bool down_ = false;
};
#endif  // INCLUDE_GAME_COMPONENTS_COLLISION_COMPONENT_H_
