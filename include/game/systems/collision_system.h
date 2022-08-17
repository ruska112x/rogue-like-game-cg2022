#ifndef INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_
// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// game
#include "../include/game/components/control_component.h"
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/saturation_component.h"
#include "../include/game/components/transform_component.h"
#include "../include/game/tags/obstacle_tag.h"
#include "../include/game/tags/takeable_tag.h"
#include "../include/lib/math/vec2.h"

class CollisionSystem : public ISystem {
 public:
  CollisionSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_COLLISION_SYSTEM_H_
