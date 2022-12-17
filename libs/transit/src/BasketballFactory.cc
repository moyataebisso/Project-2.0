#include "BasketballFactory.h"

IEntity* BasketballFactory::CreateEntity(
    JsonObject&
        entity) {  // Class that handles the creation of the Basketball entity
  std::string type = entity["type"];
  if (type.compare("basketball") == 0) {
    std::cout << "Basketball Created" << std::endl;
    return new Basketball(entity);
  }
  return nullptr;
}
