#ifndef INCLUDE_GAME_SYSTEMS_COLLISIONSYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_COLLISIONSYSTEM_H_

#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/MovementComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/tags/ObstacleTag.h"
#include "../include/game/Controls.h"

class CollisionSystem : public ISystem {
 public:
  Controls controls_;
  CollisionSystem(EntityManager* em, SystemManager* sm, Controls* controls);

  void ObstacleUpdate();
  void TakableUpdate();
  void OnUpdate();
};

#endif  // INCLUDE_GAME_SYSTEMS_COLLISIONSYSTEM_H_
