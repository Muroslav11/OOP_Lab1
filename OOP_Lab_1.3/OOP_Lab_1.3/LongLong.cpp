//////////////////////////////////////////////////////////////////////////////
// LongLong.cpp
// файл реалізації – реалізація методів та дружніх функцій
//////////////////////////////////////////////////////////////////////////////

#include "LongLong.h"
#include <iostream>
#include <sstream>

using namespace std;

LongLong::LongLong()
{
    high = 0;
    low = 0;
}

bool LongLong::SetHigh(long value)
{
    high = value;
    return true;
}

bool LongLong::SetLow(long value)
{
    low = value;
    return true;
}

bool LongLong::Init(long h, long l)
{
    // Повторне використання коду через методи доступу
    return SetHigh(h) && SetLow(l);
}

void LongLong::FromInt64(long long value)
{
    high = static_cast<long>(value >> 32);
    low = static_cast<long>(value & 0xFFFFFFFFLL);
}

long long LongLong::ToInt64() const
{
    unsigned long uLow = static_cast<unsigned long>(low);
    return (static_cast<long long>(high) << 32) | static_cast<long long>(uLow);
}

void LongLong::Read()
{
    long h, l;
    cout << "Input LongLong value:" << endl;
    cout << " High = ";
    cin >> h;
    cout << " Low = ";
    cin >> l;

    Init(h, l);
}

string LongLong::toString() const
{
    stringstream sout;
    sout << "High = " << high << ", Low = " << low
        << " (64-bit: " << ToInt64() << ")";
    return sout.str();
}

void LongLong::Display() const
{
    cout << toString() << endl;
}

// Реалізація дружньої функції додавання (як у прикладі методички)
LongLong Add(const LongLong& l, const LongLong& r)
{
    LongLong t;
    long long val1 = l.ToInt64();
    long long val2 = r.ToInt64();
    t.FromInt64(val1 + val2);
    return t;
}

// Реалізація дружньої функції множення
LongLong Multiply(const LongLong& l, const LongLong& r)
{
    LongLong t;
    long long val1 = l.ToInt64();
    long long val2 = r.ToInt64();
    t.FromInt64(val1 * val2);
    return t;
}

// Дружні функції порівняння
bool Less(const LongLong& l, const LongLong& r)
{
    return l.ToInt64() < r.ToInt64();
}

bool NotLess(const LongLong& l, const LongLong& r)
{
    return l.ToInt64() >= r.ToInt64();
}

bool Greater(const LongLong& l, const LongLong& r)
{
    return l.ToInt64() > r.ToInt64();
}