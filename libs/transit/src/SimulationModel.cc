#include "SimulationModel.h"

#include "CarFactory.h"
#include "DragonFactory.h"
#include "DroneFactory.h"
#include "HelicopterFactory.h"
#include "RobotFactory.h"
#include "BasketballFactory.h"
#include "HoopFactory.h"
#include "math/vector3.h"
#include <vector>


SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  compFactory = new CompositeFactory();
  AddFactory(new DroneFactory());
  AddFactory(new RobotFactory());
  AddFactory(new CarFactory());
  AddFactory(new HelicopterFactory());
  AddFactory(new DragonFactory());
  AddFactory(new BasketballFactory());
  AddFactory(new HoopFactory());
}

void SimulationModel::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;
  if(type.compare("hoop") == 0){
    int i = 0;
    while(i<5){
      IEntity* myNewEntity = compFactory->CreateEntity(entity);
      Vector3 currentPos = myNewEntity->GetPosition();
      currentPos[0] = currentPos[0] * 2.0;
      myNewEntity->SetPosition(currentPos);
      myNewEntity->SetGraph(graph);
      std::cout << "Updated: " << position << std::endl;
      //myNewEntity->SetPosition(coords);

  // Call AddEntity to add it to the view
      controller.AddEntity(*myNewEntity);
      entities.push_back(myNewEntity);
      i+=1;
    }
  }
  else{
    IEntity* myNewEntity = compFactory->CreateEntity(entity);
    myNewEntity->SetGraph(graph);
    // Call AddEntity to add it to the view
    controller.AddEntity(*myNewEntity);
    entities.push_back(myNewEntity);
  }

  
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
  std::string name = details["name"];
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  for (auto entity : entities) {  // Add the entity to the scheduler
    JsonObject detailsTemp = entity->GetDetails();
    std::string nameTemp = detailsTemp["name"];
    std::string typeTemp = detailsTemp["type"];
    if (name.compare(nameTemp) == 0 && typeTemp.compare("robot") == 0 &&
        entity->GetAvailability()) {
      std::string strategyName = details["search"];
      entity->SetStrategyName(strategyName);
      entity->SetDestination(Vector3(end[0], end[1], end[2]));
      scheduler.push_back(entity);
      break;
    }
  }
  controller.SendEventToView("TripScheduled", details);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
  for (int i = 0; i < entities.size(); i++) {
    entities[i]->Update(dt, scheduler);
    controller.UpdateEntity(*entities[i]);
  }
}

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}
