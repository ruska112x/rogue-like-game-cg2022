#ifndef INCLUDE_GAME_SYSTEMS_GAME_OVER_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_GAME_OVER_SYSTEM_H_

// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// components
#include "../include/game/components/color_component.h"
#include "../include/game/components/control_component.h"
#include "../include/game/components/health_component.h"
#include "../include/game/components/position_component.h"
#include "../include/game/components/step_component.h"
#include "../include/game/components/texture_component.h"
#include "../include/game/components/transform_component.h"

class GameOverSystem : public ISystem {
 public:
  Context& ctx_;
  EntityManager& em_;
  int player_id_;
  GameOverSystem(EntityManager* em, SystemManager* sm, Context* ctx, int player_id);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_GAME_OVER_SYSTEM_H_
