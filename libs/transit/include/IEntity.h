#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;
/**
 * @brief this class is responsible for
 * allowing the creation of different entities.
 */
class IEntity {
 public:
  /**
   * @brief Constructor for IEntity
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief Destructor
   */
  virtual ~IEntity() {}
  /**
   * @brief Gets id for the IEntity
   */
  virtual int GetId() const { return id; }
  /**
   * @brief Gets position for the IEntity
   */
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Gets direction for the IEntity
   */
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Gets destination for the IEntity
   */
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Gets details for the IEntity
   */
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Gets the speed for the IEntity
   */
  virtual float GetSpeed() const = 0;
  /**
   * @brief Gets the availability for the IEntity
   */
  virtual bool GetAvailability() const {};
  /**
   * @brief Gets the strategy name for the IEntity
   */
  virtual std::string GetStrategyName() {}
  /**
   * @brief Sets the availability for the IEntity
   * @param[in] choice of bool type
   */
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates the IEntity
   * @param[in] dt of double type
   * @param[in] scheduler of std::vector<IEntity*> type
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Updates the IEntity
   * @param[in] dt of double type
   * @param[in] scheduler of std::vector<IEntity*> type
   * @param[in] hoops of std::vector<IEntity*> type
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler,
                      std::vector<IEntity*> hoops) {}
  /**
   * @brief Sets the graph for the IEntity
   * @param[in] graph of const IGraph* type
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Sets the position for the IEntity
   * @param[in] pos_ of Vector3 type
   */
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Sets the direction for the IEntity
   * @param[in] dir_ of Vector3 type
   */
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Sets the destination for the IEntity
   * @param[in] des_ of Vector3 type
   */
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Sets the strategy name for the IEntity
   * @param[in] strategyName_ of std::string type
   */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Makes the IEntity rotate
   * @param[in] angle of double type
   */
  virtual void Rotate(double angle) {}
  /**
   * @brief Makes the IEntity jump
   * @param[in] height of double type
   */
  virtual void Jump(double height) {}

 protected:
  int id;
  const IGraph* graph;
};

#endif
