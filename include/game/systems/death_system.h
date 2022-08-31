#ifndef INCLUDE_GAME_SYSTEMS_DEATH_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_DEATH_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/social_credit_component.h"
#include "../include/game/components/texture_component.h"

class DeathSystem : public ISystem {
 public:
  DeathSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_DEATH_SYSTEM_H_
