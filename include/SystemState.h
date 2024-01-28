//
// Created by Тимур Ахметзянов on 27.01.2024.
//

#pragma once

#include "Particle.h"


class SystemState {
 public:
  SystemState(): time_(0), particles_(std::vector<Particle>(0)) {};
  SystemState(double time, const std::vector<Particle>& particles): time_(time), particles_(particles) {}

  const std::vector<Particle> &getParticles() const {
    return particles_;
  }

  double getTime() const {
    return time_;
  }

  void setTime(double time) {
    time_ = time;
  }

  void setParticles(const std::vector<Particle> &particles) {
    particles_ = particles;
  }

  Particle& operator[](int idx) {
    if (idx >= particles_.size() || idx < 0) {
      throw std::runtime_error("SIGSEGV");
    }
    return particles_[idx];
  }

 private:
  double time_;
  std::vector<Particle> particles_;
};
