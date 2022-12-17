#ifndef BASKETBALL_H_
#define BASKETBALL_H_
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h>

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/** @brief Represents a Basketball in a
 * physical system.
 */
class Basketball : public IEntity {
 public:
  /**
   * @brief Represents a Basketball in a physical system. Constructor for
   * Basketball object.
   * @param[in] obj of JsonObject& type
   */
  Basketball(JsonObject& obj);
  /**
   * @brief Destructor
   */
  ~Basketball();
  /**
   * @brief Gets the speed of the Basketball
   * @return float value of speed
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the position of the Basketball
   * @return Vector3 position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the direction of the Basketball
   * @return Vector3 direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the destination of the Basketball
   * @return Vector3 destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the details of the Basketball
   * @return JsonObject details
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the availibility of the Basketball
   * @return boolean value of availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Updates the position of the Basketball
   * @param[in] dt of double type
   * @param[in] scheduler of std::vector<IEntity*> type
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the position of the Basketball
   * @param[in] pos_ of Vector3 type
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction of the Basketball
   * @param[in] dir_ of Vector3 type
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the Basketball
   * @param[in] des_ of Vector3 type
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets the strategy name of basketball
   * @param[in] strategyName_ of std::string type
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }
  /**
   * @brief Sets the availability of basketball
   * @param[in] choice of bool type
   */
  void SetAvailability(bool choice);
  /**
   * @brief Rotates the Basketball
   * @param[in] angle of double type
   */
  void Rotate(double angle);
  /**
   * @brief Removing the copy constructor so that Basketball cannot be copied.
   * @param[in] basketball of const Basketball& type
   */
  Basketball(const Basketball& basketball) = delete;
  /**
   * @brief Removing the assignment operator so that Basketball cannot be
   * copied.
   * @param[in] basketball of const Basketball& type
   */
  Basketball& operator=(const Basketball& basketball) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName = "dijkstra";
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif
