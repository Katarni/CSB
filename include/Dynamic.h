//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once

#include "SystemState.h"
#include "Read.h"
#include "Update.h"
#include "Write.h"


class Dynamic {
 public:

 protected:
  std::function<Vector3(Particle)> external_f_;
  std::function<Vector3(Particle, Particle)> calculateForce_;
};
