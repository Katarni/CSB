//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#include "Write.h"

void Write::printVector3(std::ostream &out, const Vector3 &vec) {
  out << "{" << vec.getP1() << "; " << vec.getP2() << "; " << vec.getP3() << "}";
}

void Write::printParticle(std::ostream &out, const Particle &par) {
  out << std::fixed << std::setprecision(5);
  out << "Velocity: ";
  printVector3(out, par.getVelocity());
  out << " Coordinates: ";
  printVector3(out, par.getCoordinates());
  out << " Mass: " << par.getMass() << " Isospin: " << par.getI();
}

void Write::printSystemState(std::ostream &out, const Dynamic &dyn) {
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
