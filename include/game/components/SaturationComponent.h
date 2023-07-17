#ifndef INCLUDE_GAME_COMPONENTS_SATURATION_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_SATURATION_COMPONENT_H_

#include "../include/lib/ecs/component.h"

class SaturationComponent : public IComponent {
 public:
  int saturation_;

  explicit SaturationComponent(int saturation) : saturation_(saturation) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_SATURATION_COMPONENT_H_
