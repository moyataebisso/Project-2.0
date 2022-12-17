#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"
/** @brief Robot Factory inherits from IEntityFactory
 * to create the robot
 */
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief allows for the creation of the Robot
   * @param[in] entity of JsonObject& type
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
