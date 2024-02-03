#pragma once

#include "../../VWrite.h"


class WriteStandard: public VWrite {
 public:
  void printVector3(const Vector3& vec) override {
    std::cout << vec.getP1() << ' ' << vec.getP2() << ' ' << vec.getP3() << ' ';
  }

  void printParticle(const Particle& par) override {
    printVector3(par.getVelocity());
    printVector3(par.getCoordinates());
    std::cout << par.getMass() << ' ' << par.getI() << std::endl;
  }

  void printSystemState(const SystemState& state) override {
    std::cout << std::fixed << std::setprecision(13);
    for (auto particle : state.getParticles()) {
      printParticle(particle);
    }
  }
};
