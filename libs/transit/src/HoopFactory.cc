#include "HoopFactory.h"

IEntity* HoopFactory::CreateEntity(
    JsonObject& entity) {  // Class that handles the creation of the Hoop entity
  std::string type = entity["type"];
  if (type.compare("hoop") == 0) {
    std::cout << "Hoop Created" << std::endl;
    return new Hoop(entity);
  }
  return nullptr;
}
