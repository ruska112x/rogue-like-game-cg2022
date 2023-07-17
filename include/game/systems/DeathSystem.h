#ifndef INCLUDE_GAME_SYSTEMS_DEATH_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_DEATH_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/SocialCreditComponent.h"
#include "../include/game/components/TextureComponent.h"

class DeathSystem : public ISystem {
 public:
  DeathSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_DEATH_SYSTEM_H_
