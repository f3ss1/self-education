#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFile(const string& path="input.txt") {
    ifstream input(path);
    if (input) {
        string line;
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
}

void WriteFile(const string& in_path="input.txt", const string& out_path="output.txt") {
    ifstream input(in_path);
    ofstream output(out_path);
    if (input) {
        string line;
        while (getline(input, line)) {
            output << line << endl;
        }
    }
}

int main() {
    WriteFile();
    return 0;
}