#include "DroneFactory.h"

IEntity* DroneFactory::CreateEntity(
    JsonObject&
        entity) {  // Class that handles the creation of the Drone entity
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "Drone Created" << std::endl;
    return new Drone(entity);
  }
  return nullptr;
}
