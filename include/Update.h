//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "Dynamic.h"

class Update {
 public:
  virtual void updateParticles(Dynamic& dyn, double d_t) = 0;
};