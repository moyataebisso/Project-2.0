#define _USE_MATH_DEFINES
#include "Basketball.h"

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

Basketball::Basketball(JsonObject& obj) : details(obj) {
  int var1 = rand() % 2900 - 1400;
  int var2 = rand() % 700 + 250;
  double var3 = rand() % 1600 - 800;

  position = {var1, var2, var3};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Basketball::~Basketball() {
  // Delete dynamically allocated variables
}

void Basketball::Update(double dt, std::vector<IEntity*> scheduler) {
  if (toTargetPosStrategy) {
    toTargetPosStrategy->Move(this, dt);
    if (toTargetPosStrategy->IsCompleted()) {  // if current strategy is
                                               // finished
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else {
    // setting the destination right now wouldn't matter too much because later,
    // in drone.cc, we will set its destination to the closest hoop
    toTargetPosStrategy = new BeelineStrategy(GetPosition(), GetDestination());
  }
}
void Basketball::SetAvailability(bool choice) { available = choice; }

void Basketball::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
