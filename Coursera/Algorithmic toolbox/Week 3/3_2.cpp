#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;

// Creating new structure with 3 components in order to make a vector of these.

struct value_weight {
  int value, weight;
  double vpw;
};



double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  double total_value = 0.0;

  vector<value_weight> triples;

  // Filling new vector with triples.
  
  for (int i = 0; i < weights.size(); ++i) {
    value_weight j;
    j.value = values[i];
    j.weight = weights[i];
    j.vpw = values[i] * 1.0 / weights[i];
    triples.push_back(j);
  }

  // Sorting new vector by vpw component.

  std::sort(triples.begin(), triples.end(), [](const value_weight &a, value_weight &b) {
    return a.vpw > b.vpw;
  });

  // Filling capacity with items sorted by vpw.

  for (int i = 0; i < values.size(); ++i) {
    if (capacity - triples[i].weight > 0) {
      capacity -= triples[i].weight;
      total_value += triples[i].value;
    } else {
      total_value += triples[i].vpw * capacity;
      break;
    }
  }

  return total_value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
