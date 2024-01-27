//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "headers.h"
#include "SystemState.h"


class VWrite {
 public:
  virtual void printVector3(const Vector3& vec) = 0;

  virtual void printParticle(const Particle& par) = 0;

  virtual void printSystemState(const SystemState& state) = 0;
};
