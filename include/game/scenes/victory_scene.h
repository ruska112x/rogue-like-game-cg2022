#ifndef INCLUDE_GAME_SCENES_VICTORY_SCENE_H_
#define INCLUDE_GAME_SCENES_VICTORY_SCENE_H_

#include "../include/game/controls.h"
#include "../include/lib/scenes/i_scene.h"

class VictoryScene : public IScene {
  const Controls& controls_;

 public:
  VictoryScene(Context* ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_GAME_SCENES_VICTORY_SCENE_H_
