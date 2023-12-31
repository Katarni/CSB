//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#pragma once
#include "Vector3.h"


class Particle {
 public:
  Particle(Vector3& vel, Vector3& coo, double mass, double I):
          velocity_(vel), coordinates_(coo), mass_(mass), I_(I) {};

  Vector3 updateVelocity(Vector3 Force, double d_t);

  void updateCoordinates(Vector3 new_coordinates);

  static Particle fromStdString(const std::string& string);

  friend std::ostream& operator<<(std::ostream& out, Particle particle);

 private:
  Vector3 velocity_;
  Vector3 coordinates_;
  double mass_;
  double I_;
};
