#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
};


int main() {

    int n;
    cin >> n;
    vector<Student> students(n);
    for (Student& student : students) {
        cin >> student.name >> student.surname >> student.day >> student.month >> student.year;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        string request;
        double number;
        cin >> request >> number;
        number--;

        if (request == "name" && number >= 0 && number < n) {
            cout << students[number].name << ' ' << students[number].surname << endl;
        } else if (request == "date" && number >= 0 && number < n) {
            cout << students[number - 1].day << '.' << 
            students[number - 1].month << '.' << students[number - 1].year << endl;
            } else {
                cout << "bad request" << endl;
            }
        } else {
            cout << "bad request" << endl;
        }
    }


    
    return 0;
}