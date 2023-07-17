#ifndef INCLUDE_GAME_SCENES_RANDOM_SCENE_H_
#define INCLUDE_GAME_SCENES_RANDOM_SCENE_H_

#include <BearLibTerminal.h>

#include <string>

#include "../include/lib/ecs/engine.h"
#include "../include/lib/scenes/i_scene.h"
// math
#include "../include/lib/math/vec2.h"
// game
#include "../include/game/controls.h"
// components
#include "../include/game/components/ColorComponent.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/DamageComponent.h"
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/texture_component.h"
#include "../include/game/components/transform_component.h"
// tags
#include "../include/game/tags/enemy_tag.h"
#include "../include/game/tags/obstacle_tag.h"
#include "../include/game/tags/prev_door_tag.h"
#include "../include/game/tags/takeable_tag.h"
// systems
#include "../include/game/systems/collision_system.h"
#include "../include/game/systems/control_system.h"
#include "../include/game/systems/death_system.h"
#include "../include/game/systems/game_over_system.h"
#include "../include/game/systems/pursuer_system.h"
#include "../include/game/systems/render_system.h"
#include "../include/game/systems/transform_system.h"
#include "../include/game/systems/ui_system.h"

// level managers
#include "../include/game/level_manager.h"

class RandomScene : public IScene {
  const Engine engine{};
  const Controls& controls_;
  LevelManager levelManager_;
  std::string next_level_;
  int player_id_;

 public:
  RandomScene(Context* ctx, const Controls& controls, std::string next_level);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_GAME_SCENES_RANDOM_SCENE_H_
