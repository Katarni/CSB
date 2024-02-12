//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#pragma once

#include "headers.h"


class Vector3 {
 public:
  Vector3(): x_(0), y_(0), z_(0) {};
  Vector3(double x, double y, double z): x_(x), y_(y), z_(z) {};

  inline friend double operator*(const Vector3& v1, const Vector3& v2) {
    return v1.x_ * v2.x_ + v1.y_ * v2.y_ + v1.z_ * v2.z_;
  }

  inline friend Vector3 operator*(const Vector3& v1, double n) {
    return Vector3(v1.x_ * n, v1.y_ * n, v1.z_ * n);
  }
  inline friend Vector3 operator*(double n, const Vector3& v1) {
    return Vector3(v1.x_ * n, v1.y_ * n, v1.z_ * n);
  }

  inline friend Vector3 operator/(const Vector3& v1, double n) {
    return Vector3(v1.x_ / n, v1.y_ / n, v1.z_ / n);
  }

  inline friend Vector3 operator+(const Vector3& vec1, const Vector3& vec2) {
    return Vector3(vec1.x_ + vec2.x_, vec1.y_ + vec2.y_, vec1.z_ + vec2.z_);
  }
  inline Vector3& operator+=(const Vector3& other) {
    *this = *this + other;
    return *this;
  }

  inline friend Vector3 operator-(const Vector3& vec1, const Vector3& vec2) {
    return Vector3(vec1.x_ - vec2.x_, vec1.y_ - vec2.y_, vec1.z_ - vec2.z_);
  }

  double getX() const {
    return x_;
  }
  void setX(double x) {
    x_ = x;
  }

  double getY() const {
    return y_;
  }
  void setY(double y) {
    y_ = y;
  }

  double getZ() const {
    return z_;
  }
  void setZ(double z) {
    z_ = z;
  }

  friend bool operator==(const Vector3& vec1, const Vector3& vec2) {
    return vec1.x_ == vec2.x_ && vec1.y_ == vec2.y_ && vec1.z_ == vec2.z_;
  }

  friend bool operator!=(const Vector3& vec1, const Vector3& vec2) {
    return !(vec1 == vec2);
  }

 protected:
  double x_, y_, z_;
};
