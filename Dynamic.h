//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once

#include <vector>
#include "Vector3.h"
#include "Particle.h"


class Dynamic {
 public:
  void updateParticles(double d_t);

  Vector3 calculateForce(Particle first_particle, Particle second_particle);

 private:
  std::vector<Particle> particles_;
};
