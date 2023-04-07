// This problem is asked in one of the HackerEarth contests.
//
// Problem Statement: Little Robert likes mathematics. Today his teacher has
// given him two integers and asked him to find out how many integers can divide
// both the numbers. Would you like to help him in completing his school
// assignment?
//
// Input Formatting: There are two integers, a and b as input to the program.
//
// Output Formatting: Print the number of common factors of a and b. Both the
// input value should be in a range of 1 to 10^12.
//
// Example:
//
// Input: 10 15
// Output: 2
// Explanation: The common factors of 10 and 15 are 1 and 5. So the answer will
// be 2.

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
