#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    string request, s1, s2;
    map<string, string> capitals;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> request;

        if (request == "CHANGE_CAPITAL") {
            cin >> s1 >> s2;

            if (capitals.count(s1)) {
                if (capitals[s1] == s2) {
                    cout << "Country " << s1 << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << s1 << " has changed its capital from " << capitals[s1] << " to " << s2 << endl;
                }
            } else {
                cout << "Introduce new country " << s1 <<  " with capital " << s2 << endl;
            }
            capitals[s1] = s2;

        } else if (request == "RENAME") {
            cin >> s1 >> s2;
            
            if ((s1 == s2) || (!capitals.count(s1) || (capitals.count(s2)))) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country "<< s1 << "with capital " << capitals[s1] << " has been renamed to " << s2 << endl;
                capitals[s2] = capitals[s1];
                capitals.erase(s1);
            }

        } else if (request == "ABOUT") {
            cin >> s1;

            if (!capitals.count(s1)) {
                cout << "Country " << s1 << " doesn't exist" << endl;;
            } else {
                cout << "Country " << s1 << " has capital " << capitals[s1] << endl;;
            }

        } else if (request == "DUMP") {
            if (capitals.size()) {
                for (const auto& [country, capital] : capitals) {
                    cout << country << '/' << capital << ' ';
                }
            } else {
                cout << "There are no countries in the world" << endl;
            }
        }
    }

    return 0;
}