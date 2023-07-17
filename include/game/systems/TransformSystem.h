#ifndef INCLUDE_GAME_SYSTEMS_TRANSFORM_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_TRANSFORM_SYSTEM_H_
// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// game
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/StepComponent.h"
#include "../include/game/components/TransformComponent.h"
#include "../include/game/tags/EnemyTag.h"

class TransformSystem : public ISystem {
 public:
  TransformSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_TRANSFORM_SYSTEM_H_
