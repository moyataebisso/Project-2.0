#define _USE_MATH_DEFINES
#include "Drone.h"
#include <cmath>
#include <limits>
#include "AstarStrategy.h"
#include "Basketball.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SimulationModel.h"
#include "SpinDecorator.h"

Drone::Drone(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Drone::~Drone() {
  // Delete dynamically allocated variables
}
// we check for robot first
void Drone::GetNearestEntity(std::vector<IEntity*> scheduler,
                             std::vector<IEntity*> hoops) {
  std::cout << "IT WORKS 2A" << std::endl;
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    JsonObject detailsTemp = entity->GetDetails();
    std::string typeTemp = detailsTemp["type"];
    if (typeTemp.compare("robot") == 0 && entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        minDis = disToEntity;
        nearestEntity = entity;
      }
    }
  }
  // if there are no robots, we check for basketballs next
  if (!nearestEntity) {
    std::cout << "IT WORKS 2B" << std::endl;
    float minDis1 = std::numeric_limits<float>::max();
    for (auto entity : scheduler) {
      JsonObject detailsTemp = entity->GetDetails();
      std::string typeTemp = detailsTemp["type"];
      if (typeTemp.compare("basketball") == 0 && entity->GetAvailability()) {
        float disToEntity = this->position.Distance(entity->GetPosition());
        if (disToEntity <= minDis1) {
          minDis1 = disToEntity;
          nearestEntity = entity;
        }
      }
    }

    // if we do find basketball available to transport, we will adjust its
    // destination to nearest hoop
    /* if (nearestEntity) {
      float minDis2 = std::numeric_limits<float>::max();
      Vector3 closest;
      for (auto hoop : hoops) {
        JsonObject detailsTemp = hoop->GetDetails();
        std::string typeTemp = detailsTemp["type"];
        float disToEntity =
            (nearestEntity->GetPosition()).Distance(hoop->GetPosition());
        if (disToEntity <= minDis2) {
          minDis2 = disToEntity;
          closest = hoop->GetPosition();
        }
      }
      nearestEntity->SetDestination(closest);  */
    if (nearestEntity) {
    std::cout << "IT WORKS 3A" << std::endl;
    nearestEntity->SetStrategyName("beeline");
    std::cout << "IT WORKS 3B" << std::endl;
    }
  }

  if (nearestEntity) {
    std::cout << "IT WORKS 4" << std::endl;
    nearestEntity->SetAvailability(
        false);  // set availability to the nearest entity
    std::cout << nearestEntity->GetAvailability() << std::endl;
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition();
    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
    std::string targetStrategyName = nearestEntity->GetStrategyName();
    std::cout << "IT WORKS 5" << std::endl;
    if (targetStrategyName.compare("astar") == 0) {
      toTargetDestStrategy = new AstarStrategy(
          nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
      toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dfs") == 0) {
      toTargetDestStrategy = new DfsStrategy(
          nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
      toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("dijkstra") == 0) {
      toTargetDestStrategy = new DijkstraStrategy(
          nearestEntity->GetPosition(), nearestEntity->GetDestination(), graph);
      toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
      toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    } else if (targetStrategyName.compare("beeline") == 0) {
      toTargetDestStrategy = new BeelineStrategy(
          nearestEntity->GetPosition(), nearestEntity->GetDestination());
      toTargetDestStrategy = new SpinDecorator(toTargetDestStrategy);
      toTargetDestStrategy = new JumpDecorator(toTargetDestStrategy);
    }
  }
}

void Drone::Update(double dt, std::vector<IEntity*> scheduler,
                   std::vector<IEntity*> hoops) {
  /*std::cout << "IT WORKS 1" << std::endl;*/
  if (available) {
    std::cout << "IT WORKS 1A" << std::endl;
    GetNearestEntity(scheduler, hoops);
  }

  if (toTargetPosStrategy) {
    /*std::cout << "IT WORKS 1B" << std::endl;*/
    toTargetPosStrategy->Move(this, dt);
    if (toTargetPosStrategy->IsCompleted()) {
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else if (toTargetDestStrategy) {
    /*std::cout << "IT WORKS 1C" << std::endl;*/
    toTargetDestStrategy->Move(this, dt);

    // Moving the robot
    nearestEntity->SetPosition(this->GetPosition());
    nearestEntity->SetDirection(this->GetDirection());
    if (toTargetDestStrategy->IsCompleted()) {
      delete toTargetDestStrategy;
      toTargetDestStrategy = NULL;
      available = true;
      nearestEntity = NULL;
    }
  }
}

void Drone::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void Drone::Jump(double height) {
  if (goUp) {
    position.y += height;
    jumpHeight += height;
    if (jumpHeight > 5) {
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if (jumpHeight < 0) {
      goUp = true;
    }
  }
}
