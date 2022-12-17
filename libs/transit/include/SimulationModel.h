#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

/**
 * @brief this class is responsible for
 * building the simulation model handling the transit simulation.
 */
class SimulationModel {
 public:
  /**
   * @brief Constructor for the Simulation Model
   * @param[in] controller of IController& type
   */
  SimulationModel(IController& controller);
  /**
   * @brief Sets the graph in simulation
   * @param[in] graph of const IGraph* type
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Allows for the creation of simulation entities
   * @param[in] entity of JsonObject& type
   */
  void CreateEntity(JsonObject& entity);
  /**
   * @brief Schedules a trip for an object in the scene
   * @param[in] details of JsonObject& type
   */
  void ScheduleTrip(JsonObject& details);
  /**
   * @brief Updates the simulation
   * @param[in] dt of JsonObject& type
   */
  void Update(double dt);
  /**
   * @brief Adds the factory for use in simulation
   * @param[in] factory of IEntityFactory* type
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> hoops;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif
