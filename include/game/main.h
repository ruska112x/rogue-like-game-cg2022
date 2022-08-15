#ifndef INCLUDE_GAME_MAIN_H_
#define INCLUDE_GAME_MAIN_H_

#include <BearLibTerminal.h>
#include <vector>

#include "../include/game/Controls.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/MovementComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/TextureComponent.h"
#include "../include/game/systems/MovementSystem.h"
#include "../include/game/systems/RenderSystem.h"
#include "../include/game/systems/CollisionSystem.h"
#include "../include/game/tags/ObstacleTag.h"
#include "../lib/ecs/component.h"
#include "../lib/ecs/engine.h"
#include "../lib/ecs/entity.h"
#include "../lib/ecs/entity_manager.h"
#include "../lib/ecs/system.h"
#include "../lib/ecs/system_manager.h"
#include "../lib/math/vec2.h"
#include "../lib/scenes/context.h"
#include "../lib/scenes/i_scene.h"
#include "../lib/scenes/scene_manager.h"

#endif  // INCLUDE_GAME_MAIN_H_
