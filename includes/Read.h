//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#pragma once

#include "Dynamic.h"


class Read {
 public:
  virtual Vector3 readVector3(std::istream& in);
  virtual Vector3 Vector3FromStdString(const std::string& string);

  virtual Particle readParticle(std::istream& in);
  virtual Particle ParticleFromStdString(const std::string& string);
};
