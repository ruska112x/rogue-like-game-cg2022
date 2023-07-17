#ifndef INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_

#include <string>

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// game
#include "../include/game/LevelManager.h"
#include "../include/game/SceneChanger.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/DamageComponent.h"
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/MoreStepsComponent.h"
#include "../include/game/components/OpenDoorComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/SaturationComponent.h"
#include "../include/game/components/SocialCreditComponent.h"
#include "../include/game/components/StepComponent.h"
#include "../include/game/components/TextureComponent.h"
#include "../include/game/components/TransformComponent.h"
#include "../include/game/tags/EnemyTag.h"
#include "../include/game/tags/NextDoorTag.h"
#include "../include/game/tags/ObstacleTag.h"
#include "../include/game/tags/PrevDoorTag.h"
#include "../include/game/tags/TakeableTag.h"
#include "../include/lib/math/vec2.h"

class CollisionSystem : public ISystem {
 public:
  Context& ctx_;
  LevelManager& levelManager_;
  std::string prev_level_;
  std::string next_level_;
  CollisionSystem(EntityManager* em, SystemManager* sm, Context* ctx, LevelManager* levelManager,
                  std::string prev_level, std::string next_level);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_
