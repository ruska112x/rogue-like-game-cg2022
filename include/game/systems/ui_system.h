#ifndef INCLUDE_GAME_SYSTEMS_UI_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_UI_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// components
#include "../include/game/components/color_component.h"
#include "../include/game/components/control_component.h"
#include "../include/game/components/damage_component.h"
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/social_credit_component.h"
#include "../include/game/components/step_component.h"
#include "../include/game/components/texture_component.h"
#include "../include/game/components/transform_component.h"

class UISystem : public ISystem {
 public:
  int player_id_;
  EntityManager &em_;
  UISystem(EntityManager *em, SystemManager *sm, int player_id);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_UI_SYSTEM_H_
