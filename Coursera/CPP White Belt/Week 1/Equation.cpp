#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    float d = pow(b, 2) - 4 * a * c;

    if ((a == 0) || (d == 0)) {
        if (b != 0) {
            cout << -b / (2 * c); 
        } else {
            return 0;
        } 
    } else if (d > 0) {
        cout << (-b + sqrt(d)) / (2 * a) << " " << (-b - sqrt(d)) / (2 * a);
    }
    return 0;
}