#include "../include/game/systems/DoorSystem.h"

DoorSystem::DoorSystem(EntityManager *em, SystemManager *sm, LevelManager *levelManager, int close_id, int key_id)
    : ISystem(em, sm), em_(*em), levelManager_(*levelManager), close_id_(close_id), key_id_(key_id) {}

void DoorSystem::OnUpdate() {
  auto key = em_.Get(key_id_);
  auto kod = key->Get<OpenDoorComponent>();
  if (kod->is_open_) {
    em_.DeleteEntity(close_id_);
  }
}
