//
// Created by Тимур Ахметзянов on 06.02.2024.
//

#pragma once

#include "Particle.h"

std::function<Vector3(Particle, Particle)> getForceBtwPartByParams(double x_comp, double y_comp, double z_comp) {
  return [&x_comp, &y_comp, &z_comp](Particle first, Particle second) { return Vector3(x_comp, y_comp, z_comp); };
}

std::function<Vector3(Particle)> getExternalForceByParams(double x_comp, double y_comp, double z_comp) {
  return [&x_comp, &y_comp, &z_comp](Particle part) { return Vector3(x_comp, y_comp, z_comp); };
}