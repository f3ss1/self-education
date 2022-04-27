#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, n_stops, cur_n = 1;
    string stop;
    set<string> current_stops;
    map<set<string>, int> bus_stops;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> n_stops;
        for (int j = 0; j < n_stops; ++j) {
            cin >> stop;
            current_stops.insert(stop);
        }
        if (!bus_stops.count(current_stops)) {
            bus_stops[current_stops] = cur_n;
            cout << "New bus " << cur_n << endl;
            cur_n++;
        } else {
            cout << "Already exists for " << bus_stops[current_stops] << endl;
        }
        current_stops.clear();
    }
    return 0;
}