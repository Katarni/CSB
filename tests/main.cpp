#include "../includes/Dynamic.h"

int main() {
  std::function<int(int, int)> f = [](int n, int m){ std::cout << n; return m; };

  int n = 1, m = 2;
  std::cout << f(n, m);
}
