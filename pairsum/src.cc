// Problem Statement: Consider an array of integers that may contain both
// positive and negative integers, called numbers. Write a program that finds
// all the pairs of integers whose sum is equal to a given value called the
// desired sum.

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> input();
int inputSum();
int algorithm(std::vector<int>, int);

int main() {
  std::cout << algorithm(input(), inputSum());
  return 0;
}

std::vector<int> input() {
  int x = 0;
  std::vector<int> vec;
  std::cout << "vec: ";
  std::cin >> x;
  for (int i = 0, j = 0; i < x; ++i) {
    std::cout << "\nNumber: ";
    std::cin >> j;
    vec.push_back(j);
  }
  return vec;
}

int inputSum() {
  int x = 0;
  std::cout << "\nSum: ";
  std::cin >> x;
  return x;
}

int algorithm(std::vector<int> vec, int sum) {
  int total = 0;
  std::sort(vec.begin(), vec.end());
  for (size_t i = 0; i < vec.size(); ++i)
    for (size_t j = 0; j + i < vec.size(); ++j) {
      if (vec[i] + vec[j] > sum) break;
      if (vec[i] + vec[j] == sum) ++total;
    }
  return total;
}