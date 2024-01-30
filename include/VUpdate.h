//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "SystemState.h"


class VUpdate {
 public:
  virtual SystemState updateSystem(const SystemState& state,
                                      const std::function<Vector3(Particle)>& external_f,
                                      const std::function<Vector3(Particle, Particle)>& f_btw_two_par,
                                      double d_time) = 0;
};
