#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& vec) {
    for (int i = vec.size() - 2; i >= 0; --i) {
        vec.push_back(vec[i]);
        vec.erase(vec.begin() + i);
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (int i : numbers) {
        cout << i << endl;
    }
    return 0;
}