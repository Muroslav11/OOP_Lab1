#include "Money.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

Money::Money() : hryvnias(0), kopecks(0) {}

Money::Money(long h, int k)
{
    Init(h, k);
}

Money Money::fromTotalKopecks(long long totalKopecks)
{
    if (totalKopecks < 0)
        totalKopecks = 0;

    long h = static_cast<long>(totalKopecks / 100);
    int k = static_cast<int>(totalKopecks % 100);

    Money result;
    result.Init(h, k);
    return result;
}

bool Money::setHryvnias(long value)
{
    if (value >= 0)
    {
        hryvnias = value;
        return true;
    }
    hryvnias = 0;
    return false;
}

bool Money::setKopecks(int value)
{
    if (value >= 0 && value < 100)
    {
        kopecks = static_cast<unsigned char>(value);
        return true;
    }
    kopecks = 0;
    return false;
}

bool Money::Init(long h, int k)
{
    bool bH = setHryvnias(h);
    bool bK = setKopecks(k);
    return bH && bK;
}

void Money::Read()
{
    long h;
    int k;
    do
    {
        cout << "  Введіть гривні: ";
        while (!(cin >> h))
        {
            cout << "  Помилка введення! Введіть ціле число гривень: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "  Введіть копійки (0-99): ";
        while (!(cin >> k))
        {
            cout << "  Помилка введення! Введіть копійки (0-99): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!Init(h, k));
}

void Money::Display() const
{
    cout << toString();
}

string Money::toString() const
{
    stringstream sout;
    sout << hryvnias << "," << setfill('0') << setw(2) << (int)kopecks;
    return sout.str();
}

double Money::toDouble() const
{
    return hryvnias + kopecks / 100.0;
}

long long Money::toTotalKopecks() const
{
    return static_cast<long long>(hryvnias) * 100 + kopecks;
}

Money Money::add(const Money& r) const
{
    long long totalK = this->toTotalKopecks() + r.toTotalKopecks();
    return fromTotalKopecks(totalK);
}

Money Money::sub(const Money& r) const
{
    long long totalK = this->toTotalKopecks() - r.toTotalKopecks();
    return fromTotalKopecks(totalK);
}

double Money::divSums(const Money& r) const
{
    long long denominator = r.toTotalKopecks();
    if (denominator == 0)
    {
        cout << "Помилка: ділення на нульову суму!" << endl;
        return 0.0;
    }
    return static_cast<double>(this->toTotalKopecks()) / denominator;
}

Money Money::div(double val) const
{
    if (val <= 0)
    {
        cout << "Помилка: ділення на від'ємне число або нуль!" << endl;
        return Money(0, 0);
    }
    long long totalK = static_cast<long long>(round(this->toTotalKopecks() / val));
    return fromTotalKopecks(totalK);
}

Money Money::mul(double val) const
{
    if (val < 0)
    {
        cout << "Помилка: множення на від'ємне число!" << endl;
        return Money(0, 0);
    }
    long long totalK = static_cast<long long>(round(this->toTotalKopecks() * val));
    return fromTotalKopecks(totalK);
}

bool Money::equal(const Money& r) const
{
    return (hryvnias == r.hryvnias) && (kopecks == r.kopecks);
}

bool Money::great(const Money& r) const
{
    return toTotalKopecks() > r.toTotalKopecks();
}

bool Money::less(const Money& r) const
{
    return toTotalKopecks() < r.toTotalKopecks();
}