#ifndef INCLUDE_GAME_COMPONENTS_DAMAGE_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_DAMAGE_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class DamageComponent : public IComponent {
 public:
  int damage_ = 0;
  explicit DamageComponent(int damage) : damage_(damage) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_DAMAGE_COMPONENT_H_
