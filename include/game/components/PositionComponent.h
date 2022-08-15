#ifndef INCLUDE_GAME_COMPONENTS_POSITIONCOMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_POSITIONCOMPONENT_H_

#include "./lib/ecs/component.h"
#include "./lib/math/vec2.h"

class PositionComponent : public IComponent {
 public:
  Vec2 pos_;

  explicit PositionComponent(const Vec2 pos) : pos_(pos) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_POSITIONCOMPONENT_H_
