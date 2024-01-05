//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "Dynamic.h"


class Write {
 public:
  virtual void printVector3(std::ostream& out, const Vector3& vec) {
    out << "{" << vec.getP1() << "; " << vec.getP2() << "; " << vec.getP3() << "}";
  }

  virtual void printParticle(std::ostream& out, const Particle& par) {
    out << std::fixed << std::setprecision(5);
    out << "Velocity: ";
    printVector3(out, par.getVelocity());
    out << " Coordinates: ";
    printVector3(out, par.getCoordinates());
    out << " Mass: " << par.getMass() << " Isospin: " << par.getI();
  }

  virtual void printSystemState(std::ostream& out, const Dynamic& dyn) {
    if (dyn.getForce() != Vector3(0, 0, 0)) {
      out << "Force: ";
      printVector3(out, dyn.getForce());
      out << std::endl;
    }
    out << "Particles:" << std::endl;
    for (auto particle : dyn.getParticles()) {
      printParticle(out, particle);
      out << std::endl;
    }
  }
};
