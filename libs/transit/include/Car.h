#ifndef CAR_H_
#define CAR_H_
#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h>

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/** @brief Represents a Car in a
 * physical system. Moves using euler
 * integration based on a specified
 * velocity and direction.
 */
class Car : public IEntity {
 public:
  /**
   * @brief Represents a Car in a physical system.
   * @param[in] obj of JsonObject& type
   */
  Car(JsonObject& obj);
  /**
   * @brief Destructor
   */
  ~Car();
  /**
   * @brief Gets the speed of the Car
   * @return float of speed
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the position of the Car
   * @return Vector3 position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the direction of the Car
   * @return Vector3 direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the destination of the Car
   * @return Vector3 destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the details of the Car
   * @return JsonObject details
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the availibility of the Car
   * @return boolean value of availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Updates the position of the Car
   * @param[in] dt of double type
   * @param[in] scheduler of std::vector<IEntity*> type
   */
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Sets the position of the Car
   * @param[in] pos_ of Vector3 type
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction of the Car
   * @param[in] dir_ of Vector3 type
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the Car
   * @param[in] des_ of Vector3 type
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates the Car
   * @param[in] angle of double type
   */
  void Rotate(double angle);
  /**
   * @brief Removing the copy constructor so that Basketball cannot be
   * copied.
   * @param[in] basketball of const Basketball& type
   */
  Car(const Car& car) = delete;
  /**
   * @brief Removing the assignment operator so that Basketball cannot be
   * copied.
   * @param[in] basketball of const Basketball& type
   */
  Car& operator=(const Car& car) = delete;

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

#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_
