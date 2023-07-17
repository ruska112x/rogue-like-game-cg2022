#ifndef INCLUDE_GAME_SYSTEMS_UI_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_UI_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
// components
#include "../include/game/components/ColorComponent.h"
#include "../include/game/components/ControlComponent.h"
#include "../include/game/components/DamageComponent.h"
#include "../include/game/components/HealthComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/SocialCreditComponent.h"
#include "../include/game/components/StepComponent.h"
#include "../include/game/components/TextureComponent.h"
#include "../include/game/components/TransformComponent.h"

class UISystem : public ISystem {
 public:
  int player_id_;
  EntityManager &em_;
  UISystem(EntityManager *em, SystemManager *sm, int player_id);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_UI_SYSTEM_H_
