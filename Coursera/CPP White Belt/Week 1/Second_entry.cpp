#include <iostream>

using namespace std;

int main() {
    bool flag = false;
    int pos = -2;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'f') {
            if (!flag) {
                flag = true;
                pos = -1;
            } else {
                pos = i;
                break;
            }
        }
    }
    cout << pos;
    return 0;
}