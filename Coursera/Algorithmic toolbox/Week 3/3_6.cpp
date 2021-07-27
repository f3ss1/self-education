#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  
  int k = 0;

  while (true) {
    k++;
    if (n - k > k) {
      n -= k;
      summands.push_back(k);
    } else {
      summands.push_back(n);
      break;
    }
  }

  return summands;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
