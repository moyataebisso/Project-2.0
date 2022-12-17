#define _USE_MATH_DEFINES
#include "Hoop.h"

#include <stdio.h> /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <time.h>

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"

Hoop::Hoop(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);  // Hoop grabs coordinates from its field in
                                   // umn.json file
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Hoop::~Hoop() {
  // Delete dynamically allocated variables
}

void Hoop::Update(double dt,
                  std::vector<IEntity*>
                      scheduler) {  // designed to keep hoop still and not move,
                                    // as hoops are meant to stay still
  if (toTargetPosStrategy) {
    toTargetPosStrategy->Move(this, dt);
    if (toTargetPosStrategy->IsCompleted()) {  // if current strategy is
                                               // finished
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else {
    toTargetPosStrategy = new BeelineStrategy(GetPosition(), GetDestination());
  }
}
void Hoop::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
