#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"
/** @brief Composite Factory inherits from IEntityFactory
 * to make use of component entities' factories
 */
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the different component entities
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
  /**
   * @brief allows for the addition of component entities' factories
   * @param[in] factoryEntity of IEntityFactory* type
   */
  void AddFactory(IEntityFactory* factoryEntity);
  /**
   * @brief Destructor
   */
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif
