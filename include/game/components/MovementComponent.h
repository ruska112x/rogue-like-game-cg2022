#ifndef INCLUDE_GAME_COMPONENTS_MOVEMENTCOMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_MOVEMENTCOMPONENT_H_

#include "./lib/ecs/component.h"
#include "./lib/math/vec2.h"

class MovementComponent : public IComponent {
 public:
  Vec2 speed_;

  explicit MovementComponent(Vec2 speed)
  : speed_(speed) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_MOVEMENTCOMPONENT_H_
