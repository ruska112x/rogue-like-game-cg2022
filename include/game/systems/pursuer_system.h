#ifndef INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/components/control_component.h"
#include "../include/game/components/damage_component.h"
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/saturation_component.h"
#include "../include/game/components/social_credit_component.h"
#include "../include/game/components/step_component.h"
#include "../include/game/components/texture_component.h"
#include "../include/game/components/transform_component.h"
#include "../include/game/level_manager.h"
#include "../include/game/tags/enemy_tag.h"
#include "../include/game/tags/obstacle_tag.h"
#include "../include/game/tags/takeable_tag.h"
#include "../include/game/tags/wife_tag.h"

class PursuerSystem : public ISystem {
 public:
  Context& ctx_;
  EntityManager& em_;
  LevelManager& levelManager_;
  int player_id_;
  PursuerSystem(EntityManager* em, SystemManager* sm, Context* ctx, LevelManager* levelManager, int player_id);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_
