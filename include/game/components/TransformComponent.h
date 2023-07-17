#ifndef INCLUDE_GAME_COMPONENTS_TRANSFORM_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_TRANSFORM_COMPONENT_H_

#include "../include/lib/ecs/component.h"
#include "../include/lib/math/vec2.h"

class TransformComponent : public IComponent {
 public:
  Vec2 transform_vec2_ = ZeroVec2;
  bool is_transform_ = false;

  explicit TransformComponent(Vec2 transform_vec2) : transform_vec2_(transform_vec2) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_TRANSFORM_COMPONENT_H_
