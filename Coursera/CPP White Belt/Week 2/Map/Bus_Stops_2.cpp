#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, n_stops, n_route = 1;
    vector<string> current_stops;
    map<vector<string>, int> routes;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> n_stops;
        current_stops.assign(n_stops, "");
        for (string& stop : current_stops) {
            cin >> stop;
        }
        if (!routes.count(current_stops)) {
            routes[current_stops] = n_route;
            cout << "New bus " << n_route << endl;
            n_route++; 
        } else {
            cout << "Already exists for " << routes[current_stops] << endl;
        }
    }
    return 0;
}