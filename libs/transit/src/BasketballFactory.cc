#include "BasketballFactory.h"

IEntity* BasketballFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("basketball") == 0) {
    std::cout << "Basketball Created" << std::endl;
    return new Basketball(entity);
  }
  return nullptr;
}
