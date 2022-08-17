#ifndef INCLUDE_GAME_MAIN_H_
#define INCLUDE_GAME_MAIN_H_

// ecs
#include <BearLibTerminal.h>
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
// game
#include "../include/game/controls.h"
// components
#include "../include/game/components/collision_component.h"
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
#include "../include/game/systems/render_system.h"
#include "../include/game/systems/transform_system.h"

#endif  // INCLUDE_GAME_MAIN_H_
