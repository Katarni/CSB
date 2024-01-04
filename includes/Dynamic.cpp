//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#include "Dynamic.h"

void Dynamic::updateParticles(double d_t) {
  std::vector<Vector3> forces(particles_.size());
  for (int i = 0; i < particles_.size(); ++i) {
    for (int j = 0; j < particles_.size(); ++j) {
      if (i == j) continue;

      forces[j] = calculateForce_(particles_[i], particles_[j]);
    }

    Vector3 particle_force(0, 0, 0);
    for (const auto& force : forces) {
      particle_force += force;
    }

    // считаем скорость и позицию
  }
}
