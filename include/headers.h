//
// Created by Тимур Ахметзянов on 30.12.2023.
//

#pragma once

// STL
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <functional>
#include <utility>

const double kLightSpeed = 1.0;
const double kE = 2.718281828459045235;
const double kKQ = 1.19996;
const double kMinDis = 1e-9;

double sng(double num) {
  if (num > 0) return 1;
  if (num < 0) return -1;
  return 0;
}
