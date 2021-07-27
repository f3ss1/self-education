#include <iostream>

int get_change(int m) {
  int coins = 0;
  coins += m / 10;
  m = m % 10;
  coins += m / 5;
  m = m % 5;
  coins += m;
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
