#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (string& s : vec) {
        cin >> s;
    }
    // Use std::for_each() here?
    sort(vec.begin(), vec.end(), [](string a, string b) {
        string s1, s2;
        for (char& letter : a) {
            s1.push_back(tolower(letter));
        }
        for (char& letter : b) {
            s2.push_back(tolower(letter));
        }
        return s1 < s2;
    });

    for (const string& s : vec) {
        cout << s << " ";
    }

    
    return 0;
}