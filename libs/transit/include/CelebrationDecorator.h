#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the celebrations the Drone will do.
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Constructor for the Celebration Decorator
   * @param[in] strategy_ of IStrategy* type
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief Moves the entity to do celebration
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  void Move(IEntity *entity, double dt);
  /**
   * @brief Checks to see if celebration decorator is completed
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_