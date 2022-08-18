#ifndef INCLUDE_GAME_SCENES_TITLE_SCENE_H_
#define INCLUDE_GAME_SCENES_TITLE_SCENE_H_

#include <BearLibTerminal.h>

#include "../include/game/controls.h"
#include "../include/lib/scenes/i_scene.h"

class TitleScene : public IScene {
  const Controls& controls_;

 public:
  TitleScene(Context* ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_GAME_SCENES_TITLE_SCENE_H_
