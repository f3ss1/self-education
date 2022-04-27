#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int& item : vec) {
        cin >> item;
    }
    sort(vec.begin(), vec.end(), [](int i, int j) {
        return abs(i) < abs(j);
    });
    for (int& item : vec) {
        cout << item << " ";
    }

    return 0;
}