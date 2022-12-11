#ifndef HOOP_H_
#define HOOP_H_
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h>

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/** @brief Represents a Basketball Hoop in a
 * physical system. Doesn't move.
 */
class Hoop : public IEntity {
 public:
  /**
   * @brief Represents a Hoop in a physical system. Hoop doesn't move.
   * Robots will drop basketballs through the hoops.
   * @param[in] obj of JsonObject& type
   */
  Hoop(JsonObject& obj);
  /**
   * @brief Destructor
   */
  ~Hoop();
  /**
   * @brief Gets the speed of the Hoop
   * @return float
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the position of the Hoop
   * @return Vector3
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the direction of the Hoop
   * @return Vector3
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the destination of the Hoop
   * @return Vector3
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the details of the Hoop
   * @return JsonObject
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the availibility of the Hoop
   * @return boolean
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Updates the position of the Hoop
   * @param[in] dt of double type and scheduler of std::vector<IEntity*> type
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the position of the Hoop
   * @param[in] pos_ of Vector3 type
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction of the Hoop
   * @param[in] dir_ of Vector3 type
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the Hoop
   * @param[in] des_ of Vector3 type
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates the Hoop
   * @param[in] angle of double type
   */
  void Rotate(double angle);
  // Removing the copy constructor and assignment operator
  // so that Hoop cannot be coppied.
  Hoop(const Hoop& hoop) = delete;
  Hoop& operator=(const Hoop& hoop) = delete;

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
  std::string strategyName = "astar";
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif