#include <iostream>
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

// Реализуйте для класса Rational операторы ==, + и -

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
