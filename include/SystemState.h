//
// Created by Тимур Ахметзянов on 27.01.2024.
//

#pragma once
#include "Particle.h"


class SystemState {
 public:
  const std::vector<Particle> &getParticles() const {
    return particles_;
  }

  SystemState(double time, const std::vector<Particle>& particles): time_(time), particles_(particles) {}

 private:
  double time_;
  std::vector<Particle> particles_;
};