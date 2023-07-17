#ifndef INCLUDE_GAME_MAIN_H_
#define INCLUDE_GAME_MAIN_H_

#include <BearLibTerminal.h>

#include <string>

// ecs
#include "../include/lib/ecs/component.h"
#include "../include/lib/ecs/engine.h"
#include "../include/lib/ecs/entity.h"
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// math
#include "../include/lib/math/vec2.h"
// scenes
#include "../include/lib/scenes/context.h"
#include "../include/lib/scenes/i_scene.h"
#include "../include/lib/scenes/scene_manager.h"
// controls
#include "../include/game/Controls.h"
// components
#include "../include/game/components/ColorComponent.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/DamageComponent.h"
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/SocialCreditComponent.h"
#include "../include/game/components/TextureComponent.h"
#include "../include/game/components/TransformComponent.h"
// tags
#include "../include/game/tags/NextDoorTag.h"
#include "../include/game/tags/ObstacleTag.h"
#include "../include/game/tags/TakeableTag.h"
// systems
#include "../include/game/systems/CollisionSystem.h"
#include "../include/game/systems/ControlSystem.h"
#include "../include/game/systems/DeathSystem.h"
#include "../include/game/systems/GameOverSystem.h"
#include "../include/game/systems/RenderSystem.h"
#include "../include/game/systems/TransformSystem.h"
// scenes
#include "../include/game/scenes/GameOverScene.h"
#include "../include/game/scenes/GameScene.h"
#include "../include/game/scenes/RandomScene.h"
#include "../include/game/scenes/SettingsScene.h"
#include "../include/game/scenes/TitleScene.h"
#include "game/scenes/VictoryScene.h"

#endif  // INCLUDE_GAME_MAIN_H_
