//
// Created by Тимур Ахметзянов on 03.02.2024.
//

#pragma once

#include "../../VRead.h"


class StandardRead: public VRead {
 public:
  Vector3 readVector3() override {
    double p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;
    return {p1, p2, p3};
  }

  Particle readParticle() override {
    Vector3 vel = readVector3();
    Vector3 coo = readVector3();
    double mass;
    float I;
    std::cin >> mass >> I;
    return {vel, coo, mass, I};
  }

  SystemState readSystem(int particles_cnt) override {
    double time;
    std::cin >> time;
    std::vector<Particle> particles(particles_cnt);
    for (int i = 0; i < particles_cnt; ++i) {
      particles[i] = readParticle();
    }
    return {time, particles};
  }
};
