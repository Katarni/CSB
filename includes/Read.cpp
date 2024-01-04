//
// Created by Тимур Ахметзянов on 04.01.2024.
//

#include "Read.h"

Vector3 Read::readVector3(std::istream& in) {
  double p1, p2, p3;
  in >> p1 >> p2 >> p3;
  return {p1, p2, p3};
}

Vector3 Read::Vector3FromStdString(const std::string& string) {
  double param;
  Vector3 vector3;
  int cnt = 0;
  bool is_dot = false;
  int cnt_dots = 0;
  for (char let : string) {
    if (let == ' ') {
      ++cnt;
      param /= std::pow(10, cnt_dots);
      is_dot = false;
      cnt_dots = 0;
      if (cnt == 1) {
        vector3.setP1(param);
        param = 0;
      } else if (cnt == 2) {
        vector3.setP2(param);
        param = 0;
      }
    }

    if (let == '.') {
      is_dot = true;
      continue;
    }

    if (is_dot) {
      ++cnt_dots;
    }

    param = param * 10 + let - '0';
  }
  param /= std::pow(10, cnt_dots);
  vector3.setP3(param);
  return vector3;
}

Particle Read::readParticle(std::istream &in) {
  Vector3 vel = readVector3(in);
  Vector3 coo = readVector3(in);
  double mass, I;
  in >> mass >> I;
  return {vel, coo, mass, I};
}

Particle Read::ParticleFromStdString(const std::string &string) {
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
      vel = Read().Vector3FromStdString(part);
      part = "";
      is_dot = false;
      cnt_dots = 0;
      continue;
    }

    if (cnt_spaces == 6) {
      coo = Read().Vector3FromStdString(part);
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

Dynamic Read::readSystem(std::istream &in, bool read_force, int particles_cnt) {
  Vector3 force(0, 0, 0);
  if (read_force) {
    force = readVector3(in);
  }

  std::vector<Particle> particles(particles_cnt);
  for (int i = 0; i < particles_cnt; ++i) {
    particles[i] = readParticle(in);
  }
  return {force, particles};
}

Dynamic Read::readSystem(std::istream &in, bool read_force, int particles_cnt,
                         const std::function<Vector3(Particle, Particle)> &calculateForce) {
  Dynamic dyn = readSystem(in, read_force, particles_cnt);
  dyn.setCalculateForce(calculateForce);
  return dyn;
}
