#ifndef INCLUDE_GAME_SYSTEMS_RENDERSYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_RENDERSYSTEM_H_

#include <BearLibTerminal.h>

#include "../include/lib/ecs/system.h"
#include "../include/lib/ecs/entity_manager.h"
#include "../include/game/components/PositionComponent.h"
#include "../include/game/components/TextureComponent.h"

class RenderSystem : public ISystem {
 public:
  RenderSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_RENDERSYSTEM_H_
