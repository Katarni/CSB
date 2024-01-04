//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#include "Vector3.h"

Vector3 Vector3::fromStdString(const std::string& string) {
  double param;
  Vector3 vector3;
  int cnt = 0;
  bool is_dot = false;
  int cnt_dots = 0;
  for (char let : string) {
    if (let == ' ') {
      ++cnt;
      param /= std::pow(10, cnt_dots);
      is_dot = false;
      cnt_dots = 0;
      if (cnt == 1) {
        vector3.setP1(param);
        param = 0;
      } else if (cnt == 2) {
        vector3.setP2(param);
        param = 0;
      }
    }

    if (let == '.') {
      is_dot = true;
      continue;
    }

    if (is_dot) {
      ++cnt_dots;
    }

    param = param * 10 + let - '0';
  }
  param /= std::pow(10, cnt_dots);
  vector3.setP3(param);
  return vector3;
}
