#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"
/**
 * @brief this class is responsible for
 * allowing the creation of different entities' factories.
 */
class IEntityFactory {
 public:
  /**
   * @brief Destructor
   */
  virtual ~IEntityFactory() {}
  /**
   * @brief allows for the creation of various entities
   * @param[in] entity of JsonObject& type
   */
  virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif