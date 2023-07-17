#ifndef INCLUDE_GAME_SCENES_GAME_SCENE_H_
#define INCLUDE_GAME_SCENES_GAME_SCENE_H_

#include <BearLibTerminal.h>

#include <string>

#include "../include/lib/ecs/engine.h"
#include "../include/lib/scenes/i_scene.h"
// math
#include "../include/lib/math/vec2.h"
// game
#include "../include/game/Controls.h"
// components
#include "../include/game/components/ColorComponent.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/DamageComponent.h"
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/MoreStepsComponent.h"
#include "../include/game/components/OpenDoorComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/SocialCreditComponent.h"
#include "../include/game/components/TextureComponent.h"
#include "../include/game/components/TransformComponent.h"
// tags
#include "../include/game/tags/EnemyTag.h"
#include "../include/game/tags/ObstacleTag.h"
#include "../include/game/tags/PrevDoorTag.h"
#include "../include/game/tags/TakeableTag.h"
#include "../include/game/tags/WifeTag.h"
// systems
#include "../include/game/systems/CheatSystem.h"
#include "../include/game/systems/CollisionSystem.h"
#include "../include/game/systems/ControlSystem.h"
#include "../include/game/systems/DeathSystem.h"
#include "../include/game/systems/DoorSystem.h"
#include "../include/game/systems/GameOverSystem.h"
#include "../include/game/systems/PursuerSystem.h"
#include "../include/game/systems/RenderSystem.h"
#include "../include/game/systems/TransformSystem.h"
#include "../include/game/systems/UISystem.h"

// level managers
#include "../include/game/LevelManager.h"

class GameScene : public IScene {
  const Engine engine{};
  const Controls& controls_;
  LevelManager levelManager_;
  std::string level_file_;
  std::string prev_level_;
  std::string next_level_;

  int player_id_;

 public:
  GameScene(Context* ctx, const Controls& controls, std::string level_file, std::string prev_level,
            std::string next_level);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_GAME_SCENES_GAME_SCENE_H_
