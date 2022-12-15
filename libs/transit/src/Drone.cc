#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
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
    std::cout << "WE MADE IT 2" << std::endl;
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
    nearestEntity->SetStrategyName("dijkstra");
    // if we do find basketball available to transport, we will adjust its
    // destination to nearest hoop
    /* if (nearestEntity) {
      std::cout << "WE MADE IT 2" << std::endl;
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
      nearestEntity->SetDestination(closest);
    } */
  }

  if (nearestEntity) {
    std::cout << nearestEntity->GetPosition().x << std::endl;
    std::cout << nearestEntity->GetPosition().y << std::endl;
    std::cout << nearestEntity->GetPosition().z << std::endl;
    nearestEntity->SetAvailability(
        false);  // set availability to the nearest entity
    available = false;
    pickedUp = false;

    destination = nearestEntity->GetPosition();
    std::cout << "WE MADE IT 4" << std::endl;
    std::cout << nearestEntity->GetStrategyName() << std::endl;
    nearestEntity->SetDestination(Vector3(450, 450, 450));
    nearestEntity->GetDestination().Print();
    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);
    std::string targetStrategyName = nearestEntity->GetStrategyName();
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
    }
    std::cout << destination.x << std::endl;
    std::cout << destination.y << std::endl;
    std::cout << destination.z << std::endl;
  }
}

void Drone::Update(double dt, std::vector<IEntity*> scheduler,
                   std::vector<IEntity*> hoops) {
  if (available) {
    std::cout << "WE MADE IT 1" << std::endl;
    GetNearestEntity(scheduler, hoops);
  }

  if (toTargetPosStrategy) {
    /* std::cout << this->position.x << "  " << this->position.y << "  " <<
     * this->position.z << std::endl; */
    toTargetPosStrategy->Move(this, dt);
    if (toTargetPosStrategy->IsCompleted()) {
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else if (toTargetDestStrategy) {
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
  } else {
    std::cout << "WE MADE IT TO BASKETBALL" << std::endl;
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
