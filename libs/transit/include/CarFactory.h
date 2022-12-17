#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include <vector>

#include "Car.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/** @brief Car Factory inherits from IEntityFactory
 * to create the car
 */
class CarFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the Car
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
