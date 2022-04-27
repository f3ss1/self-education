#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> res;
    cin >> n;
    while (n != 0) {
        res.push_back(n % 2);
        n /= 2;
    }
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
    }
    return 0;
}