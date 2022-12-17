#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for
 * generating the DFS path that the drone will take.
 */
class DfsStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for the DFS Strategy
   * @param[in] position of Vector3 type
   * @param[in] destination of Vector3 type
   * @param[in] graph of const IGraph* type
   */
  DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destructor
   */
  ~DfsStrategy();
  /**
   * @brief Moves the entity based on DFS strategy
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Checks to see if DFS strategy is completed
   */
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // DFS_STRATEGY_H_
