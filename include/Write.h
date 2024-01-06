//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "Dynamic.h"


class Write {
 public:
  virtual void printVector3(std::ostream& out, const Vector3& vec) = 0;

  virtual void printParticle(std::ostream& out, const Particle& par) = 0;

  virtual void printSystemState(std::ostream& out, const Dynamic& dyn) = 0;
};
