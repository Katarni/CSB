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
    calculateForce_ = [](Particle par1, Particle par2) { return Vector3(); };
  }
  Dynamic(Vector3 force, const std::vector<Particle> &particles,
          const std::function<Vector3(Particle, Particle)>& calculateForce)
          : force_(force), particles_(particles), calculateForce_(calculateForce) {}

  virtual void updateParticles(double d_t) {
    std::vector<Vector3> forces(particles_.size());
    std::vector<Vector3> particles_forces_array(particles_.size());
    for (int i = 0; i < particles_.size(); ++i) {
      for (int j = 0; j < particles_.size(); ++j) {
        if (i == j) continue;

        particles_forces_array[j] = calculateForce_(particles_[i], particles_[j]);
      }

      forces[i] = force_;
      for (const auto& force : particles_forces_array) {
        forces[i] += force;
      }
    }

    for (int i = 0; i < particles_.size(); ++i) {
      particles_[i].setCoordinates({particles_[i].getCoordinates().getP1() + particles_[i].getVelocity().getP1()*d_t,
                                    particles_[i].getCoordinates().getP2() + particles_[i].getVelocity().getP2()*d_t,
                                    particles_[i].getCoordinates().getP3() + particles_[i].getVelocity().getP3()*d_t});

      particles_[i].setVelocity((forces[i] - particles_[i].getVelocity()*(forces[i]*particles_[i].getVelocity()))
                                * d_t * sqrt(1.0 - particles_[i].getVelocity()*particles_[i].getVelocity())
                                / (particles_[i].getMass() * kLightSpeed));
    }
  }

  void setForce(Vector3 force) {
    force_.setP1(force.getP1());
    force_.setP2(force.getP2());
    force_.setP3(force.getP3());
  }

  void setCalculateForce(const std::function<Vector3(Particle, Particle)> &calculateForce) {
    calculateForce_ = calculateForce;
  }

  const Vector3 &getForce() const {
    return force_;
  }

  const std::vector<Particle> &getParticles() const {
    return particles_;
  }

 protected:
  Vector3 force_;
  std::vector<Particle> particles_;
  std::function<Vector3(Particle, Particle)> calculateForce_;
};
