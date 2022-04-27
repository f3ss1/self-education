#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n_actions, day, current_month = 0;
    vector<vector<string>> list_tasks(31);
    string request, task;
    vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> n_actions;

    for (int i = 0; i < n_actions; ++i) {
        cin >> request;
        
        if (request == "ADD") {
            cin >> day >> task;
            list_tasks[day - 1].push_back(task);

        } else if (request == "DUMP") {
            cin >> day;
            cout << list_tasks[day - 1].size() << " ";
            for (string& task: list_tasks[day - 1]) {
                cout << task << " ";
            }
            cout << endl;

        } else if (request == "NEXT") {
            current_month = (current_month + 1) % 12;
            if (list_tasks.size() > days[current_month]) {
                for (int j = days[current_month]; j < list_tasks.size(); ++j) {
                    list_tasks[days[current_month] - 1].insert(end(list_tasks[days[current_month] - 1]),
                                                               begin(list_tasks[j]),
                                                               end(list_tasks[j]));
                }
            }
            list_tasks.resize(days[current_month]);
        }
    }
    return 0;
}