//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "Dynamic.h"


class Read {
 public:
  virtual Vector3 readVector3(std::istream& in) = 0;

  virtual Vector3 Vector3FromStdString(const std::string& string) = 0;

  virtual Particle readParticle(std::istream& in) = 0;

  virtual Particle ParticleFromStdString(const std::string& string) = 0;

  virtual Dynamic readSystem(std::istream& in, bool read_force, int particles_cnt) = 0;

  virtual Dynamic readSystem(std::istream& in, bool read_force, int particles_cnt,
                             const std::function<Vector3(Particle, Particle)>& calculateForce) = 0;
};
