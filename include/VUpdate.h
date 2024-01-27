//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "SystemState.h"

class VUpdate {
 public:
  virtual SystemState updateParticles(const SystemState& dyn, double time) = 0;
};
