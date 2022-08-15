#ifndef INCLUDE_GAME_SYSTEMS_RENDERSYSTEM_H_
#define INCLUDE_GAME_SYSTEMS_RENDERSYSTEM_H_

#include "../include/lib/ecs/system.h"

class RenderSystem : public ISystem {
 public:
  RenderSystem(EntityManager* em, SystemManager* sm);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_GAME_SYSTEMS_RENDERSYSTEM_H_
