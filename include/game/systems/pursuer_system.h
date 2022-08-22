#ifndef INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/components/control_component.h"
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/step_component.h"
#include "../include/game/components/texture_component.h"
#include "../include/game/components/transform_component.h"
#include "../include/game/tags/enemy_tag.h"

class PursuerSystem : public ISystem {
 public:
  EntityManager& em_;
  int player_id_;
  PursuerSystem(EntityManager* em, SystemManager* sm, int player_id);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_
