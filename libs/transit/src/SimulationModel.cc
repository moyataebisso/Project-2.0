#include "SimulationModel.h"

#include <vector>

#include "BasketballFactory.h"
#include "CarFactory.h"
#include "DragonFactory.h"
#include "DroneFactory.h"
#include "HelicopterFactory.h"
#include "HoopFactory.h"
#include "RobotFactory.h"
#include "math/vector3.h"

SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  compFactory = new CompositeFactory();
  AddFactory(new DroneFactory());
  AddFactory(new RobotFactory());
  AddFactory(new CarFactory());
  AddFactory(new HelicopterFactory());
  AddFactory(new DragonFactory());
  AddFactory(new HoopFactory());
  AddFactory(new BasketballFactory());
}

void SimulationModel::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;
  if (type.compare("hoop") == 0) {
    int i = 0;
    while (i < 5) {
      int var1 = rand() % 2900 - 1400;
      int var2 = rand() % 700 + 250;
      double var3 = rand() % 1600 - 800;
      JsonArray random_position = {var1, var2, var3};
      entity["position"] = random_position;
      IEntity* myNewEntity = compFactory->CreateEntity(entity);
      myNewEntity->SetGraph(graph);
      // myNewEntity->SetPosition(coords);

      // Call AddEntity to add it to the view
      controller.AddEntity(*myNewEntity);
      hoops.push_back(myNewEntity);
      i += 1;
    }
  } else if (type.compare("basketball") == 0) {
    IEntity* myNewEntity = compFactory->CreateEntity(entity);
    myNewEntity->SetGraph(graph);
    // Call AddEntity to add it to the view
    controller.AddEntity(*myNewEntity);

    float minDis2 = std::numeric_limits<
        float>::max();  // algorithm to calculate nearest entity based on
                        // entity's distance with current known minimum distance
    Vector3 closest;
    for (auto hoop : hoops) {
      JsonObject detailsTemp = hoop->GetDetails();
      myNewEntity->GetPosition().Print();
      hoop->GetPosition().Print();

      float disToEntity =
          (myNewEntity->GetPosition()).Distance(hoop->GetPosition());

      if (disToEntity <= minDis2) {
        minDis2 = disToEntity;
        closest = hoop->GetPosition();
      }
    }

    myNewEntity->GetDestination().Print();
    myNewEntity->SetDestination(closest);
    myNewEntity->GetDestination().Print();
    entities.push_back(myNewEntity);
    scheduler.push_back(myNewEntity);

  } else {
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
    JsonObject detailsTemp = entities[i]->GetDetails();
    std::string typeTemp = detailsTemp["type"];
    if (typeTemp.compare("drone") == 0) {
      entities[i]->Update(dt, scheduler, hoops);
      controller.UpdateEntity(*entities[i]);
    } else {
      entities[i]->Update(dt, scheduler);
      controller.UpdateEntity(*entities[i]);
    }
  }
}

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}
