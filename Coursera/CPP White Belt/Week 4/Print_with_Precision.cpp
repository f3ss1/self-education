#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (input) {
        cout << fixed << setprecision(3);
        double a;
        while (input >> a) {
            cout << a << endl;
        }
    }
    return 0;
}