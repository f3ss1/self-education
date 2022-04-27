#include <iostream>

using namespace std;

int factorial(const int x) {
    int result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int x;
    cin >> x;
    cout << factorial(x);
    return 0;
}