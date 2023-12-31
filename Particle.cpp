//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#include "Particle.h"

Vector3 Particle::updateVelocity(Vector3 Force, double d_t) {
  // обновление скорости одной частицы
}

void Particle::updateCoordinates(Vector3 new_coordinates) {
  this->coordinates_.setP1(new_coordinates.getP1());
  this->coordinates_.setP2(new_coordinates.getP2());
  this->coordinates_.setP3(new_coordinates.getP3());
}

Particle Particle::fromStdString(const std::string &string) {
  std::string part;
  int cnt_spaces = 0;
  Vector3 vel, coo;
  double mass, I;
  bool got_mass;
  int cnt_dots = 0;
  bool is_dot = false;
  for (char let : string) {
    if (let == ' ') {
      ++cnt_spaces;
    }

    if (cnt_spaces == 3) {
      vel = Vector3::fromStdString(part);
      part = "";
      is_dot = false;
      cnt_dots = 0;
      continue;
    }

    if (cnt_spaces == 6) {
      coo = Vector3::fromStdString(part);
      part = "";
      is_dot = false;
      cnt_dots = 0;
      continue;
    }

    if (cnt_spaces == 7) {
      mass /= std::pow(10, cnt_dots);
      cnt_dots = 0;
      is_dot = false;
      got_mass = true;
    }

    if (let == '.') {
      if (cnt_spaces >= 6) {
        is_dot = true;
      } else {
        part.push_back(let);
      }
      continue;
    }

    if (is_dot) {
      ++cnt_dots;
    }

    if (cnt_spaces < 6) {
      part.push_back(let);
    } else {
      if (got_mass) {
        I = I * 10 + let - '0';
      } else {
        mass = mass * 10 + let - '0';
      }
    }
  }
  I /= std::pow(10, cnt_dots);

  return Particle(vel, coo, mass, I);
}

std::ostream &operator<<(std::ostream &out, Particle particle) {
  out << std::fixed << std::setprecision(5);
  out << "Velocity: " << particle.velocity_ << " Coordinates: " << particle.coordinates_;
  out << " Mass: " << particle.mass_ << " Isospin: " << particle.I_;
  return out;
}
