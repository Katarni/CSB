//
// Created by Тимур Ахметзянов on 06.02.2024.
//

#pragma once

#include "Particle.h"

std::function<Vector3(Particle, Particle)> getYukawaForce(double v, double gamma) {
  return [&v, &gamma](const Particle& par1, const Particle& par2) {
    Vector3 r_vec = par1.getCoordinates() - par2.getCoordinates();
    double mod_r = sqrt(r_vec.getP1()*r_vec.getP1() +
                        r_vec.getP2()*r_vec.getP2() +
                        r_vec.getP3()*r_vec.getP3());

    double f_x_part1 = v / (mod_r* std::pow(kE, mod_r/gamma));
    double f_x_part2 = (mod_r + gamma) * r_vec.getP1() / (gamma * mod_r * mod_r);

    double f_y_part1 = v / (mod_r* std::pow(kE, mod_r/gamma));
    double f_y_part2 = (mod_r + gamma) * r_vec.getP2() / (gamma * mod_r * mod_r);

    double f_z_part1 = v / (mod_r* std::pow(kE, mod_r/gamma));
    double f_z_part2 = (mod_r + gamma) * r_vec.getP3() / (gamma * mod_r * mod_r);

    return Vector3(f_x_part1 * f_x_part2, f_y_part1 * f_y_part2, f_z_part1 * f_z_part2);
  };
}
