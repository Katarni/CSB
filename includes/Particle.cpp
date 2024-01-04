//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#include "Particle.h"

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

  return {vel, coo, mass, I};
}