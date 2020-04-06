//
// Created by lenovo on 28.10.2019.
//

#ifndef UNTITLED1_RATIONALNUMBER_H
#define UNTITLED1_RATIONALNUMBER_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class RationalNumber {
private:
    int numerator;
    int denominator;
    void ToCut();

public:
    RationalNumber();
    RationalNumber(int numerator);
    RationalNumber(int numerator, int denominator);

    RationalNumber Sum(RationalNumber rationalNumber) const;
    RationalNumber Subtraction(RationalNumber rationalNumber) const;
    RationalNumber Division(RationalNumber rationalNumber) const;
    RationalNumber Multiplication(RationalNumber rationalNumber) const;
    
    const std::pair<int, int> GetData();
    void SetData(const std::pair<int, int>& data);
    
    bool operator==(const RationalNumber &second) const;
    bool operator<=(const RationalNumber &second) const;
    bool operator>=(const RationalNumber &second) const;
    bool operator<(const RationalNumber &second) const;
    bool operator>(const RationalNumber &second) const;
    bool operator!=(const RationalNumber& second) const;
    
    RationalNumber& operator=(const RationalNumber &second);
    RationalNumber& operator+=(const RationalNumber &second);
    RationalNumber& operator*=(const RationalNumber &second);
    RationalNumber& operator/=(const RationalNumber &second);
    RationalNumber& operator-=(const RationalNumber &second);
    RationalNumber& operator++();
    RationalNumber& operator--();
    const RationalNumber operator++(int);
    const RationalNumber operator--(int);
    RationalNumber operator+() const;
    RationalNumber operator+(const RationalNumber &second) const;
    RationalNumber operator-() const;
    RationalNumber operator-(const RationalNumber &second) const;
    RationalNumber operator*(const RationalNumber &second) const;
    RationalNumber operator/(const RationalNumber &second) const;

    friend std::istream& operator>>(std::istream& in, const RationalNumber& number);
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& number);
};


#endif //UNTITLED1_RATIONALNUMBER_H
