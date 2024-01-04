//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#pragma once

#include "headers.h"

class Vector3 {
 public:
  Vector3(): p1_(0), p2_(0), p3_(0) {};
  Vector3(double p1, double p2, double p3): p1_(p1), p2_(p2), p3_(p3) {};

  inline friend Vector3 operator*(Vector3& v1, Vector3& v2) {
    return {v1.p1_ * v2.p1_, v1.p2_ * v2.p2_, v1.p3_ * v2.p3_};
  }
  inline friend Vector3 operator*(Vector3& v1, double n) {
    return {v1.p1_ * n, v1.p2_ * n, v1.p3_ * n};
  }
  inline friend Vector3 operator*(double n, Vector3& v1) {
    return {v1.p1_ * n, v1.p2_ * n, v1.p3_ * n};
  }

  inline friend Vector3 operator/(Vector3& v1, double n) {
    return {v1.p1_ / n, v1.p2_ / n, v1.p3_ / n};
  }

  inline friend Vector3 operator+(const Vector3& vec1, const Vector3& vec2) {
    return {vec1.p1_ + vec2.p1_, vec1.p2_ + vec2.p2_, vec1.p3_ + vec2.p3_};
  }
  inline Vector3& operator+=(const Vector3& other) {
    *this = *this + other;
    return *this;
  }

  double getP1() const {
    return p1_;
  }
  void setP1(double p1) {
    p1_ = p1;
  }

  double getP2() const {
    return p2_;
  }
  void setP2(double p2) {
    p2_ = p2;
  }

  double getP3() const {
    return p3_;
  }
  void setP3(double p3) {
    p3_ = p3;
  }

  friend bool operator==(const Vector3& vec1, const Vector3& vec2) {
    return vec1.p1_ == vec2.p1_ && vec1.p2_ == vec2.p2_ && vec1.p3_ == vec2.p3_;
  }

  friend bool operator!=(const Vector3& vec1, const Vector3& vec2) {
    return !(vec1 == vec2);
  }

 protected:
  double p1_, p2_, p3_;
};
