//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#pragma once

#include "Vector3.h"


class Particle {
 public:
  Particle(): velocity_(Vector3()), coordinates_(Vector3()), mass_(0), I_(0) {}
  Particle(Vector3& vel, Vector3& coo, double mass, float I):
          velocity_(vel), coordinates_(coo), mass_(mass), I_(I) {}
  Particle(const Particle& particle) {
    velocity_ = particle.velocity_;
    coordinates_ = particle.coordinates_;
    mass_ = particle.mass_;
    I_ = particle.I_;
  }

  Vector3 &getVelocity() {
    return velocity_;
  }

  const Vector3 &getVelocity() const {
    return velocity_;
  }

  void setVelocity(const Vector3 &velocity) {
    velocity_.setP1(velocity.getP1());
    velocity_.setP2(velocity.getP2());
    velocity_.setP3(velocity.getP3());
  }

  const Vector3 &getCoordinates() const {
    return coordinates_;
  }

  void setCoordinates(const Vector3 &coordinates) {
    coordinates_.setP1(coordinates.getP1());
    coordinates_.setP2(coordinates.getP2());
    coordinates_.setP3(coordinates.getP3());
  }

  double getMass() const {
    return mass_;
  }

  float getI() const {
    return I_;
  }

  bool isNormalVelocity() {
    return fabs(velocity_.getP1()) < kLightSpeed &&
            fabs(velocity_.getP2()) < kLightSpeed &&
            fabs(velocity_.getP3()) < kLightSpeed;
  }

 protected:
  Vector3 velocity_;
  Vector3 coordinates_;
  double mass_;
  float I_;
};
