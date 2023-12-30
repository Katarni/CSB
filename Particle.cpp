//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#include "Particle.h"

Vector3 Particle::updateVelocity(Vector3 Force, double d_t) {
  // обновление скорости одной частицы
}

void Particle::updateCoordinates(Vector3 new_coordinates) {
  this->coordinates_.setP1(new_coordinates.getP1());
  this->coordinates_.setP2(new_coordinates.getP2());
  this->coordinates_.setP3(new_coordinates.getP3());
}

Particle Particle::fromStdString(const std::string &string) {

}
