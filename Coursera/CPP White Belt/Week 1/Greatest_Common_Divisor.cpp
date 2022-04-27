#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (a > 0 && b > 0) {
        if (b > a) {
            b = b % a;
        } else {
            a = a % b;
        }
    }
    if (a > b) {
        cout << a;
    } else {
        cout << b;
    }
    return 0;
}