#ifndef INCLUDE_GAME_SCENES_SETTINGS_SCENE_H_
#define INCLUDE_GAME_SCENES_SETTINGS_SCENE_H_

#include <BearLibTerminal.h>

#include "../include/game/Controls.h"
#include "../include/game/systems/CheatSystem.h"
#include "../include/lib/ecs/engine.h"
#include "../include/lib/scenes/i_scene.h"

class SettingsScene : public IScene {
  Controls& controls_;

 public:
  const Engine engine{};
  int x{}, y{};
  char rand_accept;
  char prepare_accept;
  char ascii_accept;
  char sprite_accept;
  SettingsScene(Context* ctx, Controls* controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_GAME_SCENES_SETTINGS_SCENE_H_
