#include <array>
#include <cmath>
#include <iostream>
#include <vector>

std::array<int, 2> cin2();
int hcf(std::array<int, 2>);
int pf(int);
int nfactors(int);

int main() {
  std::cout << nfactors(pf(hcf(cin2()))) + 2;
  return 0;
}

std::array<int, 2> cin2() {
  std::array<int, 2> arr;
  std::cin >> arr[0] >> arr[1];
  return arr;
}

int hcf(std::array<int, 2> in) {
  if (!in[0] || !in[1]) return 0;
  if (in[0] == in[1]) return in[0];
  if (in[0] > in[1]) return hcf(std::array<int, 2>{in[0] - in[1], in[1]});
  return hcf(std::array<int, 2>{in[0], in[1] - in[0]});
}

int nfactors(int n) {
  int total = 0;
  for (int r = 0; r < n; ++r)
    total += std::tgamma(n + 1) / std::tgamma(r + 1) / std::tgamma(n - r + 1);
  return total;
}

int pf(int x) {
  int sol = 0;
  while (x % 2 == 0) {
    ++sol;
    x = x / 2;
  }
  for (int i = 3; i < sqrt(x); i += 2) {
    while (x % i == 0) {
      ++sol;
      x = x / i;
    }
  }
  return sol;
}
