#ifndef INCLUDE_GAME_SCENES_GAME_SCENE_H_
#define INCLUDE_GAME_SCENES_GAME_SCENE_H_

#include <BearLibTerminal.h>

#include "../include/lib/ecs/engine.h"
#include "../include/lib/scenes/i_scene.h"
// math
#include "../include/lib/math/vec2.h"
// game
#include "../include/game/controls.h"
// components
#include "../include/game/components/color_component.h"
#include "../include/game/components/control_component.h"
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/texture_component.h"
#include "../include/game/components/transform_component.h"
// tags
#include "../include/game/tags/obstacle_tag.h"
#include "../include/game/tags/takeable_tag.h"
// systems
#include "../include/game/systems/collision_system.h"
#include "../include/game/systems/control_system.h"
#include "../include/game/systems/game_over_system.h"
#include "../include/game/systems/render_system.h"
#include "../include/game/systems/transform_system.h"
#include "../include/game/systems/ui_system.h"

// level manager
#include "../include/game/level_manager.h"

class GameScene : public IScene {
  const Engine engine{};
  const Controls& controls_;

 public:
  GameScene(Context* ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_GAME_SCENES_GAME_SCENE_H_
