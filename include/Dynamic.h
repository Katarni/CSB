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

  void simulate(int num_of_iterations, double time, int num_of_particles) {
    state_ = reader_->readSystem(num_of_particles);
    for (int board = 0; board < num_of_iterations; ++board) {
      state_ = updater_->updateSystem(state_, external_f_, f_btw_two_par_, time / num_of_iterations);
    }
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
