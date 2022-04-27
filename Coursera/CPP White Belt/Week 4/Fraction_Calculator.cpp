#include <iostream>
#include <exception>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
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
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
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

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

int main() {
    Rational a, b;
    char oper;
    try {
        cin >> a >> oper >> b;

        if (oper == '+') {
            cout << a + b;
        } else if (oper == '-') {
            cout << a - b;
        } else if (oper == '*') {
            cout << a * b;
        } else if (oper == '/') {
            try {
                cout << a / b;
            } catch (domain_error& error) {
                cout << error.what();
            }
        }
    }
    catch (invalid_argument& error) {
        cout << error.what();
    }

}
