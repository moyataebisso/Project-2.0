#ifndef SPIN_DECORATOR_H_
#define SPIN_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief this class inherits from the CelebrationDecorator class and is
 * responsible for generating the spin celebration the Drone will do.
 */
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor for the Spin Decorator
   * @param[in] strategy_ of IStrategy* type
   */
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Checks to see if Spin decorator is completed
   */
  bool IsCompleted();
  /**
   * @brief Moves the entity to do spin celebration
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
