#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/** @brief Drone Factory inherits from IEntityFactory
 * to create the drone
 */
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   */
  virtual ~DroneFactory() {}
  /**
   * @brief allows for the creation of the drone
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
