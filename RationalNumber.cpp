//
// Created by lenovo on 28.10.2019.
//

#include "RationalNumber.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int _gcd(int firstNumber, int secondNumber) {
  firstNumber = abs(firstNumber);
  secondNumber = abs(secondNumber);
  while (firstNumber != 0 && secondNumber != 0) {
    if (firstNumber < secondNumber) {
      std::swap(firstNumber, secondNumber);
    }
    firstNumber = firstNumber % secondNumber;
  }
  return firstNumber + secondNumber;
}

void RationalNumber::ToCut() {
  int c = _gcd(numerator, denominator);

  if (denominator == 0) {
    throw "error";
  }
  numerator = numerator / c;
  denominator = denominator / c;
  if (denominator < 0) {
    denominator *= -1;
    numerator *= -1;
  }
}

RationalNumber::RationalNumber() : numerator(0), denominator(1) {}

RationalNumber::RationalNumber(int numerator)
    : numerator(numerator), denominator(1) {}

RationalNumber::RationalNumber(int numerator, int denominator) {
  if (!denominator) {
    throw "error";
  }
  this->numerator = numerator;
  this->denominator = denominator;
  ToCut();
}

RationalNumber RationalNumber::Sum(RationalNumber rationalNumber) const {
  RationalNumber ration_ans;
  ration_ans.numerator = numerator * rationalNumber.denominator +
                         rationalNumber.numerator * denominator;
  ration_ans.denominator = denominator * rationalNumber.denominator;
  ration_ans.ToCut();
  return ration_ans;
}

RationalNumber RationalNumber::Subtraction(RationalNumber ration_number) const {
  RationalNumber ration_ans;
  ration_ans.numerator = numerator * ration_number.denominator -
                         ration_number.numerator * denominator;
  ration_ans.denominator = denominator * ration_number.denominator;
  int _abs = 1;
  if (ration_ans.numerator < 0) {
    _abs *= -1;
  }
  if (ration_ans.denominator < 0) {
    _abs *= -1;
  }
  ration_ans.numerator = abs(ration_ans.numerator);
  ration_ans.denominator = abs(ration_ans.denominator);
  ration_ans.ToCut();
  ration_ans.numerator *= _abs;
  return ration_ans;
}

RationalNumber RationalNumber::Division(RationalNumber ration_number) const {
  RationalNumber ration_ans;
  ration_ans.numerator = numerator * ration_number.denominator;
  ration_ans.denominator = denominator * ration_number.numerator;
  try {
    ration_ans.ToCut();
  } catch (const char* error) {
    throw error;
  }
  return ration_ans;
}

RationalNumber RationalNumber::Multiplication(
    RationalNumber ration_number) const {
  RationalNumber ration_ans;
  ration_ans.numerator = numerator * ration_number.numerator;
  ration_ans.denominator = denominator * ration_number.denominator;
  ration_ans.ToCut();
  return ration_ans;
}

const std::pair<int, int> RationalNumber::GetData() {
  return {numerator, denominator};
}

void RationalNumber::SetData(const std::pair<int, int>& data) {
  numerator = data.first;
  denominator = data.second;
}

bool RationalNumber::operator==(const RationalNumber& second) const {
  return (numerator == second.numerator && numerator == 0) |
         (numerator == second.numerator && denominator == second.denominator);
}

RationalNumber& RationalNumber::operator=(const RationalNumber& second) {
  if (this == &second) {
    return *this;
  }
  numerator = second.numerator;
  denominator = second.denominator;
  return *this;
}

bool RationalNumber::operator!=(const RationalNumber& second) const {
  return !(numerator == second.numerator && denominator == second.denominator);
}

bool RationalNumber::operator<=(const RationalNumber& second) const {
  return ((numerator * second.denominator <= second.numerator * denominator));
}

bool RationalNumber::operator<(const RationalNumber& second) const {
  return ((numerator * second.denominator < second.numerator * denominator));
}

bool RationalNumber::operator>=(const RationalNumber& second) const {
  return ((numerator * second.denominator >= second.numerator * denominator));
}

bool RationalNumber::operator>(const RationalNumber& second) const {
  return ((numerator * second.denominator >= second.numerator * denominator));
}

RationalNumber& RationalNumber::operator+=(const RationalNumber& second) {
  (*this) = Sum(second);
  return *this;
}

RationalNumber& RationalNumber::operator-=(const RationalNumber& second) {
  (*this) = Subtraction(second);
  return *this;
}

RationalNumber& RationalNumber::operator*=(const RationalNumber& second) {
  (*this) = Multiplication(second);
  return *this;
}

RationalNumber& RationalNumber::operator/=(const RationalNumber& second) {
  try {
    (*this) = Division(second);
  } catch (const char* error) {
    throw error;
  }
  return *this;
}

RationalNumber RationalNumber::operator+() const {
  RationalNumber new_number = *this;
  new_number.ToCut();
  return new_number;
}

RationalNumber RationalNumber::operator-() const {
  return Multiplication(RationalNumber(-1, 1));
}

RationalNumber RationalNumber::operator+(const RationalNumber& second) const {
  return Sum(second);
}

RationalNumber RationalNumber::operator-(const RationalNumber& second) const {
  return Subtraction(second);
}

RationalNumber RationalNumber::operator*(const RationalNumber& second) const {
  return Multiplication(second);
}

RationalNumber RationalNumber::operator/(const RationalNumber& second) const {
  try {
    return Division(second);
  } catch (const char* error) {
    throw error;
  }
}

RationalNumber& RationalNumber::operator--() {
  numerator -= denominator;
  return *this;
}

RationalNumber& RationalNumber::operator++() {
  numerator += denominator;
  return *this;
}

const RationalNumber RationalNumber::operator--(int) {
  const RationalNumber new_number = *this;
  numerator -= denominator;
  return new_number;
}

const RationalNumber RationalNumber::operator++(int) {
  const RationalNumber new_number = *this;
  numerator += denominator;
  return new_number;
}

std::istream& operator>>(std::istream& in, const RationalNumber& number) {
  char separator;
  in >> number.numerator >> separator >> number.denominator;
  return in;
}

std::ostream& operator<<(std::ostream& out, const RationalNumber& number) {
  out << number.numerator << " / " << number.denominator << '\n';
  return out;
}
