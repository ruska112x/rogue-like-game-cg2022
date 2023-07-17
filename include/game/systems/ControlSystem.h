#ifndef INCLUDE_GAME_SYSTEMS_CONTROL_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_CONTROL_SYSTEM_H_
// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// game
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/TransformComponent.h"
#include "../include/game/controls.h"
class ControlSystem : public ISystem {
 public:
  const Controls& controls_;
  ControlSystem(EntityManager* em, SystemManager* sm, const Controls& controls);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_CONTROL_SYSTEM_H_
