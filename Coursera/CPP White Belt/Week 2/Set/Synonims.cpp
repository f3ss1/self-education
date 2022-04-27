#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    string request, word_1, word_2;
    map<string, set<string>> dict;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> request;

        if (request == "ADD") {
            cin >> word_1 >> word_2;
            dict[word_1].insert(word_2);
            dict[word_2].insert(word_1);
        } else if (request == "COUNT") {
            cin >> word_1;
            cout << dict[word_1].size() << endl;
        } else if (request == "CHECK") {
            cin >> word_1 >> word_2;
            if (dict[word_1].count(word_2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}