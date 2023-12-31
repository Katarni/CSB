//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#include "Dynamic.h"

void Dynamic::updateParticles(double d_t) {
  std::vector<Vector3> forces(particles_.size());
  for (int i = 0; i < particles_.size(); ++i) {
    for (int j = 0; j < particles_.size(); ++j) {
      if (i == j) continue;

      forces[j] = calculateForce(particles_[i], particles_[j]);
    }

    // считаем сумму сил
  }

  for (int i = 0; i < particles_.size(); ++i) {
    // рассчитываем скорость
  }

  for (int i = 0; i < particles_.size(); ++i) {
    // пересчитываем позицию
  }
}

Vector3 Dynamic::calculateForce(Particle target_particle, Particle impacting_particle) {
  return Vector3();
}

std::istream &operator>>(std::istream &in, std::pair<Dynamic&, bool> dynamic) {
  if (dynamic.second) {
    std::string force;
    getline(in, force);
    dynamic.first.setForce(Vector3::fromStdString(force));
  }

  std::string line;
  while (getline(in, line)) {
    dynamic.first.push_back(Particle::fromStdString(line));
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, const std::pair<Dynamic, bool>& dynamic) {
  if (dynamic.first.force_ != Vector3(0, 0, 0)) {
    out << "Force: " << dynamic.first.force_ << std::endl;
  }
  out << "Particles:" << std::endl;
  for (auto particle : dynamic.first.particles_) {
    out << particle << std::endl;
  }
  return out;
}
