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
    Person(const string& name, const string& surname, const int& year) {
        names_list.push_back({name, year});
        surnames_list.push_back({surname, year});
        birth_year = year;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year > birth_year) {
            Name_Surname new_name = {first_name, year};
            names_list.push_back(new_name);
            sort(names_list.begin(), names_list.end(), [](Name_Surname x, Name_Surname y) {return x.year < y.year;});
        }
        
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year > birth_year) {
            Name_Surname new_surname = {last_name, year};
            surnames_list.push_back(new_surname);
            sort(surnames_list.begin(), surnames_list.end(), [](Name_Surname x, Name_Surname y) {return x.year < y.year;});
        }
    }
    string GetFullName(int year) {
        if (year < birth_year) {
            return "No person";
        }
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

    string GetFullNameWithHistory(int year) {
        if (year < birth_year) {
            return "No person";
        }
        vector<string> names, surnames;
        names = get_list_before_year(names_list, year);
        surnames = get_list_before_year(surnames_list, year);
        string s_names = "", s_surnames = "";

        if (!names.size() && !surnames.size()) {
            return "Incognito";
        } else if (!names.size()) {
            s_surnames = generate_sequence(surnames);
            return s_surnames + "with unknown first name";
        } else if (!surnames.size()) {
            s_names = generate_sequence(names);
            return s_names + "with unknown last name";
        } else {
            s_names = generate_sequence(names);
            s_surnames = generate_sequence(surnames);
            return s_names + s_surnames;
        }
    }

    void print() {
        for (Name_Surname s : names_list) {
            cout << s.value << " ";
        }
        cout << endl;

        for (Name_Surname s : surnames_list) {
            cout << s.value << " ";
        }
        cout << endl;

    }
    
private:
    vector<Name_Surname> names_list, surnames_list;
    int birth_year;

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

    vector<string> get_list_before_year(const vector<Name_Surname>& vec, const int& year) {
        vector<string> result;
        for (const Name_Surname& item : vec) {
            if (item.year > year) {
                break;
            }
            result.push_back(item.value);
        }
        return result;
    }

    string generate_sequence(vector<string> vec) {
        string s;
        reverse(vec.begin(), vec.end());
        s = vec[0] + " ";
        if (vec.size() > 1) {
            s += '(';
            bool flag = false;
            for (int i = 1; i < vec.size(); ++i) {
                if (vec[i-1] != vec[i]){
                    s += (vec[i] + ", ");
                    flag = true;
                }
                
        }
            s.pop_back();
            s.pop_back();
            if (flag) {
                s += ") ";
            }
            
        }
        return s;
    }

};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
