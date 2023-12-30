//
// Created by Тимур Ахметзянов on 30.12.2023.
//

#include "Dynamic.h"

std::istream &operator>>(std::istream &in, std::pair<Dynamic&, bool> dynamic) {
  if (dynamic.second) {
    std::string force;
    getline(in, force);
    dynamic.first.setForce(Vector3::fromStdString(force));
  }

  std::string line;
  while (getline(in, line)) {
    dynamic.first.addParticle(Particle::fromStdString(line));
  }

  return in;
}