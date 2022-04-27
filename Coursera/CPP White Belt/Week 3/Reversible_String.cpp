#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
    public:
    ReversibleString() {
        s = "";
    }

    ReversibleString(const string& s_) {
        s = s_;
    }

    void Reverse() {
        reverse(s.begin(), s.end());
    }

    string ToString() const {
        return s;
    }

    private:
        string s;


};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}