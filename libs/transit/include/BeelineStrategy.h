#ifndef BEELINE_H_
#define BEELINE_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the beeline path that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for the Beeline Strategy
   * @param[in] position of Vector3 type
   * @param[in] destination of Vector3 type
   */
  BeelineStrategy(Vector3 position, Vector3 destination);
  /**
   * @brief Destructor
   */
  ~BeelineStrategy();
  /**
   * @brief Moves the entity based on Beeline strategy
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Checks to see if Beeline strategy is completed
   */
  bool IsCompleted();

 private:
  Vector3 position;
  Vector3 destination;
};      // end class
#endif  // BEELINE_H_