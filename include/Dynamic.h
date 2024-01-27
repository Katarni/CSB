//
// Created by Тимур Ахметзянов on 20.10.2023.
//

#pragma once

#include "VRead.h"
#include "VUpdate.h"
#include "VWrite.h"


class Dynamic {
 public:
  Dynamic(std::unique_ptr<VRead> reader,
          std::unique_ptr<VUpdate> updater,
          std::unique_ptr<VWrite> writer,
          const std::function<Vector3(Particle)>& external_f,
          const std::function<Vector3(Particle, Particle)>& f_btw_two_par) {
    external_f_ = external_f;
    f_btw_two_par_ = f_btw_two_par;

    reader_ = std::move(reader);
    updater_ = std::move(updater);
    writer_ = std::move(writer);
  }

  void simulate(int time) {
    state_ = updater_->updateParticles(state_, external_f_, f_btw_two_par_, time);
    writer_->printSystemState(state_);
  }

 protected:
  SystemState state_;

  std::function<Vector3(Particle)> external_f_;
  std::function<Vector3(Particle, Particle)> f_btw_two_par_;

  std::unique_ptr<VRead> reader_;
  std::unique_ptr<VWrite> writer_;
  std::unique_ptr<VUpdate> updater_;
};
