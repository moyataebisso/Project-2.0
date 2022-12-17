#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/** @brief Represents a Robot in a
 * physical system. Moves using euler
 * integration based on a specified
 * velocity and direction.
 */
class Robot : public IEntity {
 public:
  /**
   * @brief Represents a Robot in a physical system.
   * @param[in] obj of JsonObject& type
   */
  Robot(JsonObject& obj);
  /**
   * @brief Destructor
   */
  ~Robot() override = default;
  /**
   * @brief Gets the position of the Robot
   * @return Vector3 position
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Gets the direction of the Robot
   * @return Vector3 direction
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Gets the destination of the Robot
   * @return Vector3 destination
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Gets the availibility of the Robot
   * @return boolean value of availability
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Gets the details of the Robot
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Gets the speed of the Robot
   * @return float of speed
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Gets the strategy name of the Robot
   * @return strategy name of Robot
   */
  std::string GetStrategyName() { return strategyName; }
  /**
   * @brief Sets the availability of the Robot
   * @param[in] choice of bool type
   */
  void SetAvailability(bool choice);
  /**
   * @brief Sets the position of the Robot
   * @param[in] pos_ of Vector3 type
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Sets the direction of the Robot
   * @param[in] dir_ of Vector3 type
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Sets the destination of the Robot
   * @param[in] des_ of Vector3 type
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Sets the Robot's strategy name
   * @param[in] strategyName_ of std::string type
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }
  /**
   * @brief Rotates the Robot
   * @param[in] angle of double type
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // ROBOT_H
