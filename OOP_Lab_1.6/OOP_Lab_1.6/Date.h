#pragma once
#include <string>
#include <sstream>

using namespace std;

class Date {
public:
    // Вкладений клас Triad (трійка чисел)
    class Triad {
    private:
        int first;
        int second;
        int third;

    public:
        Triad();
        Triad(int f, int s, int t);

        int GetFirst() const { return first; }
        int GetSecond() const { return second; }
        int GetThird() const { return third; }

        bool SetFirst(int value);
        bool SetSecond(int value);
        bool SetThird(int value);

        bool Init(int f, int s, int t);
        void Read();
        void Display() const;
        string toString() const;

        bool IsGreater(const Triad& t) const;
        bool IsLess(const Triad& t) const;
        bool IsEqual(const Triad& t) const;
        bool IsNotEqual(const Triad& t) const;
    };

private:
    Triad triad; // Поле-контейнер типу вкладеного класу Triad (рік, місяць, день)

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