#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> result;
    for (const auto& [key, value] : m) {
        result.insert(value);
    }
    return result;

}