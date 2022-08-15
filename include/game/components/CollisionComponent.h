#ifndef INCLUDE_GAME_SYSTEMS_COLLISIONCOMPONENT_H_
#define INCLUDE_GAME_SYSTEMS_COLLISIONCOMPONENT_H_

#include "./lib/ecs/component.h"

class CollisionComponent : public IComponent {
 public:
  bool up_free_ = false;
  bool right_free_ = false;
  bool down_free_ = false;
  bool left_free_ = false;
};

#endif  // INCLUDE_GAME_SYSTEMS_COLLISIONCOMPONENT_H_
