#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n_operations, person, worried;
    vector<bool> queue;
    string request;

    cin >> n_operations;

    for (int i = 0; i < n_operations; ++i) {
        cin >> request;
        if (request == "WORRY") {
            cin >> person;
            queue[person] = true;

        } else if (request == "QUIET") {
            cin >> person;
            queue[person] = false;

        } else if (request == "COME") {
            cin >> person;
            queue.resize(person + queue.size());

        } else if (request == "WORRY_COUNT") {
            worried = 0;
            for (const bool& person : queue) {
                if (person) {
                    worried++;
                }
            }
            cout << worried;
        }
    }
    return 0;
}