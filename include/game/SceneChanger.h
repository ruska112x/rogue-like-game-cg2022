#ifndef INCLUDE_GAME_SCENE_CHANGER_H_
#define INCLUDE_GAME_SCENE_CHANGER_H_

#include <string>

#include "../include/lib/scenes/context.h"

class SceneChanger {
 public:
  Context& ctx_;
  explicit SceneChanger(Context* ctx) : ctx_(*ctx) {}
  void changeLevel(std::string name) {
    ctx_.scene_ = name;
  }
};

#endif  // INCLUDE_GAME_SCENE_CHANGER_H_
