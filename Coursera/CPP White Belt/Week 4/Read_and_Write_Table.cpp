#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int a, b;
    input >> a >> b;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int current;
            input >> current;
            input.ignore(1);
            cout << setw(10) << current;
            if (j != b - 1) {
                cout << ' ';
            }
        }
        if (i != a - 1) {
            cout << endl;
        }
    }
    return 0;
}