#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& vec) {
    vector<int> result;
    for (int i = vec.size() - 1; i >= 0; --i) {
        result.push_back(vec[i]);
    }
    return result;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> result; 
    result = Reversed(numbers);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}