#ifndef BASKETBALL_FACTORY_H_
#define BASKETBALL_FACTORY_H_

#include <vector>

#include "Basketball.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/** @brief Basketball Factory inherits from IEntityFactory
 * to create the Basketball
 */
class BasketballFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the Basketball
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
