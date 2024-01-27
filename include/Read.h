//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "SystemState.h"


class Read {
 public:
  virtual Vector3 readVector3() = 0;

  virtual Particle readParticle() = 0;

  virtual SystemState readSystem(int particles_cnt) = 0;
};
