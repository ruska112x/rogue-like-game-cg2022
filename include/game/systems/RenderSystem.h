#ifndef INCLUDE_GAME_SYSTEMS_RENDER_SYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_RENDER_SYSTEM_H_
// ecs
#include "../include/lib/ecs/entity_manager.h"
#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/system_manager.h"
#include "../include/lib/scenes/context.h"
// game
#include "../include/game/components/ColorComponent.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/TextureComponent.h"

class RenderSystem : public ISystem {
 public:
  Context& ctx_;
  RenderSystem(EntityManager* em, SystemManager* sm, Context* ctx);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_RENDER_SYSTEM_H_
