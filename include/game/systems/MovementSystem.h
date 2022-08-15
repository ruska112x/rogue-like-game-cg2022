#ifndef INCLUDE_GAME_SYSTEMS_MOVEMENTSYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_MOVEMENTSYSTEM_H_

#include "../include/game/Controls.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/MovementComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"

class MovementSystem : public ISystem {
 public:
  Controls controls_;
  MovementSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_MOVEMENTSYSTEM_H_
