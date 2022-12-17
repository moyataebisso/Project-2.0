#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/** @brief Represents a drone in a physical system.
 * Drones move using euler integration based on a specified velocity and
 * direction.
 */
class Drone : public IEntity {
 public:
  /**
   * @brief Represents a Drone in a physical system.
   * @param[in] obj of JsonObject& type
   */
  Drone(JsonObject& obj);
  /**
   * @brief Destructor
   */
  ~Drone();
  /**
   * @brief Gets the speed of the Drone
   * @return float of speed
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the position of the drone
   * @return Vector3 position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the direction of the drone
   * @return Vector3 direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the destination of the drone
   * @return Vector3 destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the details of the drone
   * @return JsonObject details
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Gets the availibility of the drone
   * @return boolean value of availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the nearest entity to the drone
   * @param[in] scheduler of std::vector<IEntity*> type
   * @param[in] hoops of std::vector<IEntity*> type
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler,
                        std::vector<IEntity*> hoops);
  /**
   * @brief Updates the position of the Drone
   * @param[in] dt of double type
   * @param[in] scheduler of std::vector<IEntity*> type
   * @param[in] hoops of std::vector<IEntity*> type
   */
  void Update(double dt, std::vector<IEntity*> scheduler,
              std::vector<IEntity*> hoops);
  /**
   * @brief Sets the position of the Drone
   * @param[in] pos_ of Vector3 type
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction of the Drone
   * @param[in] dir_ of Vector3 type
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the Drone
   * @param[in] des_ of Vector3 type
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates the drone
   * @param[in] angle of double type
   */
  void Rotate(double angle);
  /**
   * @brief Makes the drone jump
   * @param[in] height of double type
   */
  void Jump(double height);
  /**
   * @brief Removing the copy constructor so that Drone cannot be
   * copied.
   * @param[in] drone of const Drone& type
   */
  Drone(const Drone& drone) = delete;
  /**
   * @brief Removing the assignment operator so that Drone cannot be
   * copied.
   * @param[in] drone of const Drone& type
   */
  Drone& operator=(const Drone& drone) = delete;

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
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
};

#endif
