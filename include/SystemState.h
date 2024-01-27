//
// Created by Тимур Ахметзянов on 27.01.2024.
//

#pragma once

#include "headers.h"
#include "Particle.h"


class SystemState {
 public:
  SystemState(): time_(0), particles_(std::vector<Particle>(0)) {};
  SystemState(double time, const std::vector<Particle>& particles): time_(time), particles_(particles) {}

  const std::vector<Particle> &getParticles() const {
    return particles_;
  }

 private:
  double time_;
  std::vector<Particle> particles_;
};
