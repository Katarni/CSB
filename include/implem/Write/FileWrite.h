//
// Created by Тимур Ахметзянов on 03.02.2024.
//

#pragma once

#include "../../VWrite.h"


class FileWrite: public VWrite {
 public:
  FileWrite(const std::string& file_path) {
    ostream_.open(file_path);
  }

  FileWrite(const std::ofstream& ostream) {
    ostream_.copyfmt(ostream)
  }

  void printVector3(const Vector3& vec) override {
    ostream_ << vec.getP1() << ' ' << vec.getP2() << ' ' << vec.getP3() << ' ';
  }

  void printParticle(const Particle& par) override {
    printVector3(par.getVelocity());
    printVector3(par.getCoordinates());
    ostream_ << par.getMass() << ' ' << par.getI();
  }

  void printSystemState(const SystemState& state) override {
    ostream_ << std::fixed << std::setprecision(13);
    for (auto particle : state.getParticles()) {
      printParticle(particle);
      ostream_ << std::endl;
    }
  }
 private:

  std::ofstream ostream_;
};
