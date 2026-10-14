#include "Date.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Date::Date() {
    triad = Triad(2000, 1, 1);
}

Date::Date(int year, int month, int day) {
    if (!Init(year, month, day)) {
        triad = Triad(2000, 1, 1);
    }
}

bool Date::IsLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::IsValid(int year, int month, int day) const {
    if (year <= 0) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && IsLeapYear(year)) {
        if (day > 29) return false;
    }
    else {
        if (day > daysInMonth[month]) return false;
    }
    return true;
}

bool Date::SetDate(int year, int month, int day) {
    if (IsValid(year, month, day)) {
        triad.Init(year, month, day);
        return true;
    }
    return false;
}

bool Date::SetYear(int year) {
    return SetDate(year, GetMonth(), GetDay());
}

bool Date::SetMonth(int month) {
    return SetDate(GetYear(), month, GetDay());
}

bool Date::SetDay(int day) {
    return SetDate(GetYear(), GetMonth(), day);
}

bool Date::Init(int year, int month, int day) {
    return SetDate(year, month, day);
}

void Date::Read() {
    int y, m, d;
    do {
        cout << "Введіть дату:" << endl;
        cout << "  Рік = ? "; cin >> y;
        cout << "  Місяць = ? "; cin >> m;
        cout << "  День = ? "; cin >> d;
        if (!IsValid(y, m, d)) {
            cout << "Помилка: недійсна дата! Спробуйте ще раз." << endl;
        }
    } while (!Init(y, m, d));
}

void Date::Display() const {
    cout << toString() << endl;
}

string Date::toString() const {
    stringstream sout;
    sout << setfill('0')
        << setw(4) << GetYear() << "."
        << setw(2) << GetMonth() << "."
        << setw(2) << GetDay();
    return sout.str();
}

bool Date::IsEqual(const Date& d) const {
    return triad.IsEqual(d.triad);
}

bool Date::IsNotEqual(const Date& d) const {
    return !IsEqual(d);
}

bool Date::IsGreater(const Date& d) const {
    return triad.IsGreater(d.triad);
}

bool Date::IsLess(const Date& d) const {
    return triad.IsLess(d.triad);
}

bool Date::IsGreaterOrEqual(const Date& d) const {
    return IsGreater(d) || IsEqual(d);
}

bool Date::IsLessOrEqual(const Date& d) const {
    return IsLess(d) || IsEqual(d);
}