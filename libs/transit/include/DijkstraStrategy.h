#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for
 * generating the dijkstra path that the drone will take.
 */
class DijkstraStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for the Dijkstra Strategy
   * @param[in] position of Vector3 type
   * @param[in] destination of Vector3 type
   * @param[in] graph of const IGraph* type
   */
  DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destructor
   */
  ~DijkstraStrategy();
  /**
   * @brief Moves the entity based on Dijkstra strategy
   * @param[in] entity of IEntity* type
   * @param[in] dt of double type
   */
  void Move(IEntity* entity, double dt);
  /**
   * @brief Checks to see if Dijkstra strategy is completed
   */
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // Dijkstra_STRATEGY_H_
