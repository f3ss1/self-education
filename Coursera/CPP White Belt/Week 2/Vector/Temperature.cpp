#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, average = 0;
    cin >> n;
    vector<int> temp(n);
    for (int& i : temp) {
        cin >> i;
        average += i;
    }
    average /= n;

    vector<int> indices;
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] > average) {
            indices.push_back(i);
        }
    }
    cout << indices.size() << endl;

    for (int& i : indices) {
        cout << i << " ";
    }
    return 0;
}