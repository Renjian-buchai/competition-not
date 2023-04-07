// This competitive coding question is asked in Goldman Sachs.
//
// Problem Statement: Suppose you have given the stock prices for respective
// days like (100, 180, 260, 310, 40, 535, 695). The stock price for the 1st day
// is 100, the 2nd day it is 180 and so on. Write a Python program to determine
// what days the user should buy and sell the stocks to get the maximum profit.
//
// In the above case, in the following scenarios user will get maximum profit.
//
// Buy stock on 1st day (100)
// Sell stock on 4th day (310)
// Buy stock on 5th day  (100)
// Sell stock on 7th day (695)
// Algorithm steps:
//
// Find the local minima (buying stock)
// Find local maxima (selling stock)
// Repeat until all days are covered.

#include <iostream>
#include <vector>

std::vector<int> input();
void algorithm(std::vector<int>);

int main() {
  algorithm(input());
  return 0;
}

std::vector<int> input() {
  int x = 0;
  int n = 0;
  std::vector<int> vec;
  std::cin >> x;
  for (int i = 0; i < x; ++i) {
    std::cin >> n;
    vec.push_back(n);
  }
  return vec;
}

void algorithm(std::vector<int> vec) {
  for (size_t buy = 0, sell = 1, focus = 0, i = 0; i < vec.size(); ++i) {
    if (vec[focus] > vec[sell]) {
      std::cout << "Buy at " << buy + 1 << ", sell at " << focus + 1 << "\n";
      buy = sell;
      ++sell, focus;
    } else if (vec[focus] == vec[sell]) {
      ++sell, focus;
    } else if (vec[focus] < vec[sell]) {
      ++sell, focus;
      focus = sell - 1;
    }
  }
  return;
}