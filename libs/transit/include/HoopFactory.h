#ifndef HOOP_FACTORY_H_
#define HOOP_FACTORY_H_

#include <vector>

#include "Hoop.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/** @brief Hoop Factory inherits from IEntityFactory
 * to create the Hoop
 */
class HoopFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the Hoop
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_HOOPFACTORY_H_
