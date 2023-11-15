//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once

#include <vector>
#include "Vector3.h"
#include "Particle.h"


class Dynamic {
 public:
  void updateParticles(long double d_t);

 private:
  std::vector<Particle> particles_;
};
