#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

/**
 * @brief Abstract controller class used in the Transit Service.
 */
class IController {
 public:
  virtual ~IController() {}
  /**
   * @brief Adds an entity to the program
   * @param[in] entity of const IEntity& type
   */
  virtual void AddEntity(const IEntity& entity) = 0;
  /**
   * @brief Updates an entity in the program
   * @param[in] entity of const IEntity& type
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /**
   * @brief Removes an entity from the program
   * @param[in] id of int type
   */
  virtual void RemoveEntity(int id) = 0;
  /**
   * @brief Adds a path to the program
   * @param[in] id of int type
   * @param[in] path of const std::vector<std::vector<float> >& type
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /**
   * @brief Removes a path from the program
   * @param[in] id of int type
   */
  virtual void RemovePath(int id) = 0;
  /**
   * @brief Allows messages to be passed back to the view
   * @param[in] event of const std::string& type
   * @param[in] details of const JsonObject& type
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif
