//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once
#include "Particle.h"


class Dynamic {
 public:
  Dynamic() = default;
  Dynamic(Vector3 force, const std::vector<Particle> &particles)
          : force_(force), particles_(particles) {
    calculateForce_ = [](Particle par1, Particle pa2) { return Vector3(); };
  }
  Dynamic(Vector3 force, const std::vector<Particle> &particles,
          const std::function<Vector3(Particle, Particle)>& calculateForce)
          : force_(force), particles_(particles), calculateForce_(calculateForce) {}

  virtual void updateParticles(double d_t);

  void setForce(Vector3 force) {
    force_.setP1(force.getP1());
    force_.setP2(force.getP2());
    force_.setP3(force.getP3());
  }

  void push_back(Particle particle) {
    particles_.push_back(particle);
  }

  const Vector3 &getForce() const {
    return force_;
  }

  const std::vector<Particle> &getParticles() const {
    return particles_;
  }

  void setParticles(const std::vector<Particle> &particles) {
    particles_ = particles;
  }

 protected:
  Vector3 force_;
  std::vector<Particle> particles_;
  std::function<Vector3(Particle, Particle)> calculateForce_;
};
