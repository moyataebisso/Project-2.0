#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include <vector>

#include "Helicopter.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/** @brief Helicopter Factory inherits from IEntityFactory
 * to create the helicopter
 */
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the Helicopter
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
