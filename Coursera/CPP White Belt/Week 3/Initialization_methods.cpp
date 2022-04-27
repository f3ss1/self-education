#include <iostream>

using namespace std;

struct Incognizable {
    int a = 1, b = 2;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}