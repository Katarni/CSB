//
// Created by Тимур Ахметзянов on 03.02.2024.
//

#pragma once

#include "../../VWrite.h"


class WriteDat: public VWrite {
 public:
  WriteDat(const std::string& file_path) {
    ostream.open(file_path);
  }

  void printVector3(const Vector3& vec) override {
    ostream << vec.getP1() << ' ' << vec.getP2() << ' ' << vec.getP3() << ' ';
  }

  void printParticle(const Particle& par) override {
    printVector3(par.getVelocity());
    printVector3(par.getCoordinates());
    ostream << std::endl;
  }

  void printSystemState(const SystemState& state) override {
    ostream << std::fixed << std::setprecision(13);
    for (auto particle : state.getParticles()) {
      printParticle(particle);
    }
  }
 private:

  std::ofstream ostream;
};
