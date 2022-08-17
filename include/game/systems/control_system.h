#ifndef INCLUDE_GAME_SYSTEMS_CONTROL_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_CONTROL_SYSTEM_H_
// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// game
#include "../include/game/components/control_component.h"
#include "../include/game/controls.h"
class ControlSystem : public ISystem {
 public:
  Controls* controls_;
  ControlSystem(EntityManager* em, SystemManager* sm, Controls* controls);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_CONTROL_SYSTEM_H_