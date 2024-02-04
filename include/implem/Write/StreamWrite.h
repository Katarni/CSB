#pragma once

#include "../../VWrite.h"


class StreamWrite: public VWrite {
 public:
  StreamWrite(const StreamWrite& write) {
    ostream_.copyfmt(write.ostream_);
  }

  StreamWrite(const std::ostream& ostream) {
    ostream_.copyfmt(ostream);
  }

  void printVector3(const Vector3& vec) override {
    ostream_ << vec.getP1() << ' ' << vec.getP2() << ' ' << vec.getP3() << ' ';
  }

  void printParticle(const Particle& par) override {
    printVector3(par.getVelocity());
    printVector3(par.getCoordinates());
    ostream_ << par.getMass() << ' ' << par.getI() << std::endl;
  }

  void printSystemState(const SystemState& state) override {
    ostream_ << std::fixed << std::setprecision(13);
    for (auto particle : state.getParticles()) {
      printParticle(particle);
    }
  }

 private:
  std::ostream ostream_{nullptr};
};
