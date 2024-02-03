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

  void simulate(int num_of_iterations, double time, size_t num_of_particles, bool save_states) {
    state_ = reader_->readSystem(num_of_particles);

    std::vector<SystemState> states(0);
    if (save_states) {
      states.reserve(num_of_iterations);
    }

    for (int board = 0; board < num_of_iterations; ++board) {
      state_ = updater_->updateSystem(state_, external_f_, f_btw_two_par_, time / num_of_iterations);

      if (save_states) {
        states.emplace_back(state_);
      }
    }

    if (save_states) {
      for (int i = 0; i < num_of_particles; ++i) {
        writer_->printSystemState(states[i]);
      }
    } else {
      writer_->printSystemState(state_);
    }
  }

 protected:
  SystemState state_;

  std::function<Vector3(Particle)> external_f_;
  std::function<Vector3(Particle, Particle)> f_btw_two_par_;

  std::unique_ptr<VRead> reader_;
  std::unique_ptr<VWrite> writer_;
  std::unique_ptr<VUpdate> updater_;
};
