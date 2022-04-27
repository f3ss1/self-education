#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& a, vector<string>& b) {
    for (auto i : a) {
        b.push_back(i);
    }
    a.clear();
}

int main() {
    vector<string> a = {"1", "2"};
    vector<string> b = {"3", "4"};
    MoveStrings(a, b);
    for (auto i : b) {
        cout << i << " ";
    }
    return 0;
}
