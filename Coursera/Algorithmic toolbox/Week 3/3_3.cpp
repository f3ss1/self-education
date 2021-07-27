#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> stops) {
    int refills = 0;

    int cur_loc = 0;
    stops.push_back(dist);
    int i = 0;
    while (true) {
        if (cur_loc + tank >= dist) {
            return refills;
        }
        if (stops[i] > tank + cur_loc) {
            if (cur_loc == stops[i - 1]) {
                return -1;
            } else {
                refills++;
                cur_loc = stops[i - 1];
                i--;
            }

        }
        i++;
    }
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
