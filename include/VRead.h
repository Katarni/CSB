//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "SystemState.h"


class VRead {
 public:
  virtual Vector3 readVector3() = 0;

  virtual Particle readParticle() = 0;

  virtual SystemState readSystem(int num_of_particles) = 0;
};
