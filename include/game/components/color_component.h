#ifndef INCLUDE_GAME_COMPONENTS_COLOR_COMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_COLOR_COMPONENT_H_

#include <BearLibTerminal.h>
#include "../include/lib/ecs/component.h"

class ColorComponent : public IComponent {
 public:
  color_t color_ = color_from_name("white");

  explicit ColorComponent(color_t color) : color_(color) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_COLOR_COMPONENT_H_
