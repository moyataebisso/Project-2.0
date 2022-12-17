#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;
/**
 * @brief this class for generating the paths that the drone will take.
 */
class IStrategy {
 public:
  /**
   * @brief Moves the entity based on IStrategy
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  virtual void Move(IEntity* entity, double dt) = 0;
  /**
   * @brief Checks to see if IStrategy is completed
   */
  virtual bool IsCompleted() = 0;

 protected:
  // IGraph object to be used in the simulation.
  const IGraph* graph;
};  // close class

#endif  // ISTRATEGY_H_
