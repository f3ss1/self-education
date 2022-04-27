#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct DatabaseObject {
    Date date;
    string event;
};

Date ParseDate(const string& s) {
    stringstream sstream;
    sstream << s;

    int a, b, c;
    char char_1, char_2;
    sstream >> a >> char_1 >> b >> char_2 >> c;
    if (char_1 == '-' && char_2 == '-') {
        if (b > 0 && b <= 12) {
            if (c > 0 && c <= 31) {
                return {a, b, c};
            } else {
                throw invalid_argument("Day value is invalid: " + to_string(c));
            }    
        } else {
            throw invalid_argument("Month value is invalid: " + to_string(b));
        }
    } else {
        cout << char_1 << " " << char_2;
        throw invalid_argument("Wrong date format: " + s);
    }
}

// cout

ostream& operator<<(ostream& stream, Date& date) {
    return stream << setw(4) << setfill('0') <<  date.year << '-' << setw(2) << setfill('0') << date.month << '-' << setw(2) << setfill('0') << date.day;
}

ostream& operator<<(ostream& stream, DatabaseObject object) {
    return stream << object.date << ' ' << object.event;
}

// bool operators

bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year);
}

bool operator==(const DatabaseObject& lhs, const DatabaseObject& rhs) {
    return (lhs.date == rhs.date && lhs.event == rhs.event);
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.year < rhs.year) {
        return true;
    } else if (lhs.year > rhs.year) {
        return false;
    } else {
        if (lhs.month < rhs.month) {
            return true;
        } else if (lhs.month > rhs.month) {
            return false;
        } else {
            return (lhs.day < rhs.day);
        }
    }
}

bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.year > rhs.year) {
        return true;
    } else if (lhs.year < rhs.year) {
        return false;
    } else {
        if (lhs.month > rhs.month) {
            return true;
        } else if (lhs.month < rhs.month) {
            return false;
        } else {
            return (lhs.day > rhs.day);
        }
    }
}

bool operator<(const DatabaseObject& lhs, const DatabaseObject& rhs) {
    if (lhs.date < rhs.date) {
        return true;
    } else if (lhs.date > rhs.date) {
        return false;
    } else {
        return (lhs.event < rhs.event);
    }
}

bool operator>(const DatabaseObject& lhs, const DatabaseObject& rhs) {
    if (lhs.date > rhs.date) {
        return true;
    } else if (lhs.date < rhs.date) {
        return false;
    } else {
        return (lhs.event > rhs.event);
    }
}

// class

class Database {
    public:

    void add(const DatabaseObject& object) {
        data.push_back(object);
        sort(data.begin(), data.end());
    }

    void del(const DatabaseObject& object) {
        int initial_len = size(data);
        data.erase(remove(data.begin(), data.end(), object), data.end());
        if (initial_len != size(data)) {
            cout << "Deleted successfully" << endl;
        } else {
            cout << "Event not found" << endl;
        }
    }

    void del_day(const Date& date) {
        int i = 0;
        for (DatabaseObject& object : data) {
            if (object.date == date) {
                data.erase(remove(data.begin(), data.end(), object), data.end());
                i++;
            }
        }
        cout << "Deleted " << i << " events" << endl;
    }

    void print() {
        for (DatabaseObject object : data) {
            cout << object << endl;
        }
    }

    void find(const Date& date) {
        for (DatabaseObject object : data) {
            if (object.date == date) {
                cout << object.event << endl;
            } else if (object.date > date) {
                break;
            }
        }
    }

    int len() {
        return size(data);
    }
    
    private:
    vector<DatabaseObject> data;
};



int main() {
    Database database;

    string line;
    try{
        while (getline(cin, line)) {
            stringstream ss(line);

            string request;
            ss >> request;
            if (request == "Add") {
                string s, event;
                ss >> s >> event;
                DatabaseObject object = {ParseDate(s), event};
                database.add(object);
            } else if (request == "Find") {
                string s, event;
                ss >> s >> event;
                Date date = ParseDate(s);
                database.find(date);
            } else if (request == "Print") {
                database.print();
            } else if (request == "Del") {
                string s, event;
                ss >> s;
                if (!ss.eof()) {
                    ss >> event;
                    DatabaseObject object = {ParseDate(s), event};
                    database.del(object);
                } else {
                    Date date = ParseDate(s);
                    database.del_day(date);
                }
                
            } else if (request.empty()) {
                break;
            } else {
                throw logic_error("Unknown command: " + request); 
            }
        }
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    
    
    return 0;
}