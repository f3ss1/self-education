#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    set<string> result;
    string med;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> med;
        result.insert(med);
    }
    cout << result.size();
    return 0;
}