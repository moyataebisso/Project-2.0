#define _USE_MATH_DEFINES
#include "HelicopterFactory.h"
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

unsigned int seedh = time(0);

Helicopter::Helicopter(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  available = true;
}

Helicopter::~Helicopter() {
  // Delete dynamically allocated variables
}

void Helicopter::Update(double dt, std::vector<IEntity*> scheduler) {
  if (toTargetPosStrategy) {
    toTargetPosStrategy->Move(this, dt);
    if (toTargetPosStrategy->IsCompleted()) {  // if current strategy is
                                               // finished
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else {
    float x_rand = rand_r(&seedh) % 2900 - 1400;  // -1400 to 1500
    float y_rand = 250;                   // 240 to 1000
    float z_rand = rand_r(&seedh) % 1600 - 800;   // -800 to 800
    // Vector3 random_dest = direction;

    SetDestination(Vector3(x_rand, y_rand, z_rand));
    toTargetPosStrategy =
        new BeelineStrategy(GetPosition(), GetDestination());
  }
}
void Helicopter::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}
