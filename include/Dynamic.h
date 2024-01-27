//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once

#include "SystemState.h"
#include "VRead.h"
#include "VUpdate.h"
#include "VWrite.h"


class Dynamic {
 public:
  Dynamic(VRead* reader, VUpdate* updater, VWrite* writer,
          const std::function<Vector3(Particle)>& external_f,
          const std::function<Vector3(Particle, Particle)>& f_btw_two_par) {
    external_f_ = external_f;
    f_btw_two_par_ = f_btw_two_par;

    reader_ = static_cast<std::unique_ptr<VRead>>(reader);
    writer_ = static_cast<std::unique_ptr<VWrite>>(writer);
    updater_ = static_cast<std::unique_ptr<VUpdate>>(updater);
  }

  SystemState simulate(int time) {
    state_ = updater_->updateParticles(state_, time);
    return state_;
  }

 protected:
  SystemState state_;

  std::function<Vector3(Particle)> external_f_;
  std::function<Vector3(Particle, Particle)> f_btw_two_par_;

  std::unique_ptr<VRead> reader_;
  std::unique_ptr<VWrite> writer_;
  std::unique_ptr<VUpdate> updater_;
};
