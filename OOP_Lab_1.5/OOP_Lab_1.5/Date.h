#pragma once
#include "Triad.h"

class Date {
private:
    Triad triad; // Трійка чисел: рік, місяць, день

    bool IsLeapYear(int year) const;

public:
    Date();
    Date(int year, int month, int day);

    bool IsValid(int year, int month, int day) const;

    Triad GetTriad() const { return triad; }
    int GetYear() const { return triad.GetFirst(); }
    int GetMonth() const { return triad.GetSecond(); }
    int GetDay() const { return triad.GetThird(); }

    bool SetDate(int year, int month, int day);
    bool SetYear(int year);
    bool SetMonth(int month);
    bool SetDay(int day);

    bool Init(int year, int month, int day);
    void Read();
    void Display() const;
    string toString() const;

    bool IsEqual(const Date& d) const;
    bool IsNotEqual(const Date& d) const;
    bool IsGreater(const Date& d) const;
    bool IsLess(const Date& d) const;
    bool IsGreaterOrEqual(const Date& d) const;
    bool IsLessOrEqual(const Date& d) const;
};