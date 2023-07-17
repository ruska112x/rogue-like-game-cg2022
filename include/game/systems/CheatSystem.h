#ifndef INCLUDE_GAME_SYSTEMS_CHEAT_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_CHEAT_SYSTEM_H_
// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/controls.h"

class CheatSystem : public ISystem {
 public:
  const Controls& controls_;
  Context& ctx_;
  CheatSystem(EntityManager* em, SystemManager* sm, const Controls& controls, Context* ctx);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_CHEAT_SYSTEM_H_
