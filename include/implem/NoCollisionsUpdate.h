#pragma once

#include "VUpdate.h"


class NoCollisionsUpdate: public VUpdate {
 public:
  SystemState updateSystem(const SystemState& state,
                       const std::function<Vector3(Particle)>& external_f,
                       const std::function<Vector3(Particle, Particle)>& f_btw_two_par,
                       double d_time) override {
    std::vector<Vector3> forces(state.size());
    std::vector<Vector3> particles_forces_array(state.size());
    for (int i = 0; i < state.size(); ++i) {
      for (int j = 0; j < state.size(); ++j) {
        if (i == j) continue;

        particles_forces_array[j] = f_btw_two_par(state[i], state[j]);
      }

      forces[i] = external_f(state[i]);
      for (const auto& force : particles_forces_array) {
        forces[i] += force;
      }
    }

    SystemState new_state = state;

    for (int i = 0; i < state.size(); ++i) {
      new_state[i].setCoordinates({state[i].getCoordinates().getP1() + state[i].getVelocity().getP1()*d_time,
                                   state[i].getCoordinates().getP2() + state[i].getVelocity().getP2()*d_time,
                                    state[i].getCoordinates().getP3() + state[i].getVelocity().getP3()*d_time});

      Vector3 numerator = d_time *
                          kLightSpeed *
                          (forces[i] - state[i].getVelocity() * (forces[i]*state[i].getVelocity()));
      double gamma = sqrt(1 - state[i].getVelocity()*state[i].getVelocity());

      new_state[i].setVelocity(numerator * gamma / state[i].getMass() + state[i].getVelocity());
    }

    new_state.setTime(new_state.getTime() + d_time);

    return new_state;
  }
};
