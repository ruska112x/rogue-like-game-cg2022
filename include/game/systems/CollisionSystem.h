#ifndef INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_

#include <string>

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// game
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
#include "../include/game/level_manager.h"
#include "../include/game/scene_changer.h"
#include "../include/game/tags/enemy_tag.h"
#include "../include/game/tags/next_door_tag.h"
#include "../include/game/tags/obstacle_tag.h"
#include "../include/game/tags/prev_door_tag.h"
#include "../include/game/tags/takeable_tag.h"
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
