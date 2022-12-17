#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inherits from the IStrategy class and is responsible for generating the astar path that the drone will take.
 */
class AstarStrategy : public IStrategy {
public:
    /**
     * @brief Constructor for the Astar Strategy
     * @param[in] position of Vector3 type
     * @param[in] destination of Vector3 type
     * @param[in] graph of const IGraph* type
     */
    AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    /**
     * @brief Destructor
     */
    ~AstarStrategy();
    /**
     * @brief Moves the entity based on Astar strategy
     * @param[in] entity of IEntity* type
     * @param[in] dt of double type 
     */
    void Move(IEntity* entity, double dt);
    /**
     * @brief Checks to see if Astar strategy is completed
     */
    bool IsCompleted();

private:
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
}; //end class
#endif // ASTAR_STRATEGY_H_