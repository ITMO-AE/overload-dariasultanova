#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);

    int Numerator() const;
    int Denominator() const;

    friend bool operator== (const Rational& a, const Rational& b);
    friend Rational operator+ (const Rational& a, const Rational& b);
    friend Rational operator- (const Rational& a, const Rational& b);

    friend Rational operator/ (const Rational& a, const Rational& b);
    friend Rational operator* (const Rational& a, const Rational& b);

    friend std::ostream& operator<< (std::ostream &os, Rational const &r);
    friend std::istream& operator>> (std::istream &is, Rational &r);

private:
    int numerator_;
    int denominator_;
    static int greatestCommonDivisor(int a, int b);
};

#endif // RATIONAL_H
