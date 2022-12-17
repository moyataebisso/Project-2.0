#ifndef JUMP_DECORATOR_H_
#define JUMP_DECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"
/**
 * @brief this class inherits from the CelebrationDecorator class and is
 * responsible for generating the jump celebration the Drone will do.
 */
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Constructor for the Jump Decorator
   * @param[in] strategy_ of IStrategy* type
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Checks to see if jump decorator is completed
   */
  bool IsCompleted();
  /**
   * @brief Moves the entity to do jump celebration
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // JUMP_DECORATOR_H_