#include <iostream>
#include <istream>
#include <sstream>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        int gcd_ = gcd(numerator, denominator);
        if (denominator < 0) {
            denominator *= (-1);
            numerator *= (-1);
        }
        num = numerator / gcd_;
        denom = denominator / gcd_;
        if (num == 0) {
            denom = 1;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num;
    int denom;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational result(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), 
                    lhs.Denominator() * rhs.Denominator());
    return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational result(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), 
                    lhs.Denominator() * rhs.Denominator());
    return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational result(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
    return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational result(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
    return result;
}

istream& operator >>(istream& stream, Rational& rational) {
    int a, b;
    char c;
    stream >> a >> c >> b;
    if (stream && c == '/') {
        Rational result(a, b);
        rational = result;
    }

    return stream;
}

ostream& operator <<(ostream& stream, const Rational& rational) {
    return stream << rational.Numerator() << '/' << rational.Denominator();
}





int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}
