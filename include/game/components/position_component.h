#ifndef INCLUDE_GAME_COMPONENTS_POSITION_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_POSITION_COMPONENT_H_

#include "../include/lib/ecs/component.h"
#include "../include/lib/math/vec2.h"

class PositionComponent : public IComponent {
 public:
  Vec2 position_ = OnesVec2;

  explicit PositionComponent(Vec2 position) : position_(position) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_POSITION_COMPONENT_H_
