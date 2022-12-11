#ifndef DRAGON_FACTORY_H_
#define DRAGON_FACTORY_H_

#include <vector>

#include "Dragon.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/** @brief Dragon Factory inherits from IEntityFactory
 * to create the helicopter
 */
class DragonFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the Dragon
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
