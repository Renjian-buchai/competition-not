#include <array>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> cin();
int product(int, std::vector<int>, int);
int sum(int, std::vector<int>, int);
bool interface(std::vector<int>);

int main() {
  std::cout << interface(cin());
  return 0;
}

std::vector<int> cin() {
  std::vector<int> vec;
  int x = 0, y = 0;
  std::cin >> x;
  for (int i = 0; i < x; ++i) {
    std::cin >> y;
    vec.push_back(y);
  }
  return vec;
}

bool interface(std::vector<int> vec) {
  return (product(1, vec, vec.size()) % sum(0, vec, vec.size()) == 0);
}

int product(int total, std::vector<int> vec, int index) {
  if (index == 1) return total * vec[0];
  return product(total * vec[index - 1], vec, index - 1);
}

int sum(int total, std::vector<int> vec, int index) {
  if (index == 1) return total + vec[0];
  return sum(total + vec[index - 1], vec, index - 1);
}