#ifndef INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_PURSUER_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/LevelManager.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/DamageComponent.h"
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/SaturationComponent.h"
#include "../include/game/components/SocialCreditComponent.h"
#include "../include/game/components/StepComponent.h"
#include "../include/game/components/TextureComponent.h"
#include "../include/game/components/TransformComponent.h"
#include "../include/game/tags/EnemyTag.h"
#include "../include/game/tags/ObstacleTag.h"
#include "../include/game/tags/TakeableTag.h"
#include "../include/game/tags/WifeTag.h"

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
