//
// Created by Тимур Ахметзянов on 21.10.2023.
//

#include "Vector3.h"

Vector3 Vector3::fromStdString(const std::string& string) {
  double param;
  Vector3 vector3;
  int cnt = 0;
  for (char let : string) {
    if (let == ' ') {
      ++cnt;
      if (cnt == 1) {
        vector3.setP1(param);
        param = 0;
      } else if (cnt == 2) {
        vector3.setP2(param);
        param = 0;
      } else if (cnt == 3) {
        vector3.setP3(param);
        param = 0;
      }
    }

    param = param * 10 + let - '0';
  }
  return vector3;
}
