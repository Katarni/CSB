//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#pragma once


class Vector3 {
 public:
  Vector3(): p1_(0), p2_(0), p3_(0) {};
  Vector3(long double p1, long double p2, long double p3): p1_(p1), p2_(p2), p3_(p3) {};

  inline friend Vector3 operator*(Vector3& v1, Vector3& v2) {
    return Vector3(v1.p1_ * v2.p1_, v1.p2_ * v2.p2_, v1.p3_ * v2.p3_);
  }
  inline friend Vector3 operator*(Vector3& v1, long double n) {
    return Vector3(v1.p1_ * n, v1.p2_ * n, v1.p3_ * n);
  }
  inline friend Vector3 operator*(long double n, Vector3& v1) {
    return Vector3(v1.p1_ * n, v1.p2_ * n, v1.p3_ * n);
  }
  inline friend Vector3 operator/(Vector3& v1, long double n) {
    return Vector3(v1.p1_ / n, v1.p2_ / n, v1.p3_ / n);
  }

 private:
  long double p1_, p2_, p3_;
};
