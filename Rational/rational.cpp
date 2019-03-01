#include <math.h>
#include <assert.h>
#include <iostream>
#include "rational.h"

Rational::Rational(): numerator_(0), denominator_(1)
{
}

Rational::Rational(int numerator, int denominator) :
    numerator_(numerator), denominator_(denominator)
{
    assert(denominator_ != 0);
    if (numerator_ == 0) {
        denominator_ = 1;
    }

    if ((numerator_ > 0 && denominator_ < 0) || (numerator_ < 0 && denominator_ < 0)) {
        numerator_ *= -1;
        denominator_ *= -1;
    }

    int gcd = greatestCommonDivisor(numerator_, denominator_);

    numerator_ /= gcd;
    denominator_ /= gcd;
}

int Rational::Numerator() const
{
    return numerator_;
}

int Rational::Denominator() const
{
    return denominator_;
}

std::istream& operator>> (std::istream &is, Rational &r)
{
    char c;

    is >> r.numerator_ >> c >> r.denominator_;
    int gcd = Rational::greatestCommonDivisor(r.numerator_, r.denominator_);
    r.numerator_ /= gcd;
    r.denominator_ /= gcd;
    return is;
}

std::ostream& operator<< (std::ostream &os, const Rational &r)
{
    return os << r.numerator_ << "/" << r.denominator_;
}

bool operator== (const Rational &a, const Rational &b)
{
    if (a.Numerator() == b.Numerator() && a.Denominator() == b.Denominator()) {
        return true;
    }
    else {
        return false;
    }
}

Rational operator+ (const Rational &a, const Rational &b)
{
    int numenator = a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator();
    int denominator = a.Denominator() * b.Denominator();
    return Rational(numenator, denominator);
}

Rational operator- (const Rational &a, const Rational &b)
{
    int numenator = a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator();
    int denominator = a.Denominator() * b.Denominator();
    return Rational(numenator, denominator);
}

Rational operator/ (const Rational& a, const Rational& b) {
    assert(b.Numerator() != 0);
    return Rational(a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator());
}

Rational operator* (const Rational& a, const Rational& b) {
    return Rational(a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator());
}

int Rational::greatestCommonDivisor(int a, int b)
{
    if (b == 0) {
        return abs(a);
    }
    return greatestCommonDivisor(b, a % b);
}

