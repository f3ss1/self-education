#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Name_Surname {
    string value;
    int year;
};

struct Record {
    string name, surname;
};


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        Name_Surname new_name = {first_name, year};
        names_list.push_back(new_name);
        sort(names_list.begin(), names_list.end(), [](Name_Surname x, Name_Surname y) {return x.year < y.year;});
    }
    void ChangeLastName(int year, const string& last_name) {
        Name_Surname new_surname = {last_name, year};
        surnames_list.push_back(new_surname);
        sort(surnames_list.begin(), surnames_list.end(), [](Name_Surname x, Name_Surname y) {return x.year < y.year;});
    }
    string GetFullName(int year) {
        Record current_record = GetRecord(year);

        if (current_record.name == "unknown first name" && current_record.surname == "unknown last name") {
            return "Incognito";
        } else if (current_record.name == "unknown first name") {
            return current_record.surname + ' ' + "with unknown first name";
        } else if (current_record.surname == "unknown last name") {
            return current_record.name + ' ' + "with unknown last name";
        } else {
            return current_record.name + ' ' + current_record.surname; 
        }
    }
    
private:
    vector<Name_Surname> names_list, surnames_list;

    Record GetRecord(int year) {
        string name, surname;
        if (names_list[0].year > year) {
            name = "unknown first name";
        } else {
            name = names_list[names_list.size() - 1].value;
            for (int i = 1; i < names_list.size(); ++i) {
                if (names_list[i].year > year) {
                    name = names_list[i - 1].value;
                    break;
                }
            }
        }
    
        if (surnames_list[0].year > year) {
            surname = "unknown last name";
        } else {
            surname = surnames_list[surnames_list.size() - 1].value;
            for (int i = 1; i < surnames_list.size(); ++i) {
                if (surnames_list[i].year > year) {
                    surname = surnames_list[i - 1].value;
                    break;
                }
            }
        }
        Record result = {name, surname}; 
        return result;
    }

};

int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
      cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
      cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
      cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}