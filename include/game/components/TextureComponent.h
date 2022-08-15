#ifndef INCLUDE_GAME_COMPONENTS_TEXTURECOMPONENT_H_
#define INCLUDE_GAME_COMPONENTS_TEXTURECOMPONENT_H_

#include "./lib/ecs/component.h"

class TextureComponent : public IComponent {
 public:
  char symbol_;

  explicit TextureComponent(char symbol) : symbol_(symbol) {}
};

#endif  // INCLUDE_GAME_COMPONENTS_TEXTURECOMPONENT_H_
