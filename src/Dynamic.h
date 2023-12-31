//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once
#include "Particle.h"


class Dynamic {
 public:
  Dynamic() = default;
  Dynamic(const std::vector<Particle>& particles): particles_(particles) {}
  Dynamic(Vector3 force, const std::vector<Particle>& particles): force_(force), particles_(particles) {}

  void updateParticles(double d_t);

  void setForce(Vector3 force) {
    force_.setP1(force.getP1());
    force_.setP2(force.getP2());
    force_.setP3(force.getP3());
  }

  friend std::istream& operator>>(std::istream& in, std::pair<Dynamic&, bool> dynamic);
  friend std::ostream& operator<<(std::ostream& out, const std::pair<Dynamic, bool>& dynamic);

  void push_back(Particle particle) {
    particles_.push_back(particle);
  }

 private:
  Vector3 force_;
  std::vector<Particle> particles_;

  Vector3 calculateForce(Particle first_particle, Particle second_particle);
};
