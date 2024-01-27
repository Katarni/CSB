//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "Dynamic.h"


class Read {
 public:
  virtual Vector3 readVector3() = 0;

  virtual Particle readParticle() = 0;

  virtual Dynamic readSystem(int particles_cnt) = 0;
};
