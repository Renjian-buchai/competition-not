// Problem Statement:
//
// You have given a string. You need to remove all the duplicates from the
// string.
//
// The final output string should contain each character only once. The
// respective order of the characters inside the string should remain the same.
//
// You can only traverse the string at once.
//
// Example:
//
// Input string: ababacd
// Output string: abcd

#include <iostream>
#include <set>
#include <string>

std::set<char> toset(std::string);
std::string tostr(std::set<char>);
std::string input();

int main() {
  std::cout << tostr(toset(input()));
  return 0;
}

std::string input() {
  std::string x = "";
  std::cin >> x;
  return x;
}

std::set<char> toset(std::string x) {
  std::set<char> eax;
  for (size_t i = 0; i < x.length(); ++i) eax.insert(x[i]);
  return eax;
}

std::string tostr(std::set<char> x) {
  std::string eax = "";
  for (auto it = x.begin(); it != x.end(); ++it) eax += *it;
  return eax;
}