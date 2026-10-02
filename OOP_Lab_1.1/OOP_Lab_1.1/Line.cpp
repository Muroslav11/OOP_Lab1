#include "Line.h"
#include <iostream>

using namespace std;

bool Line::SetFirst(double value)
{
    if (value != 0)
    {
        first = value;
        return true;
    }
    else
    {
        first = 1;
        return false;
    }
}

bool Line::SetSecond(double value)
{
    second = value;
    return true;
}

bool Line::Init(double a, double b)
{
    return SetFirst(a) && SetSecond(b);
}

void Line::Read()
{
    double a, b;

    do
    {
        cout << "Введіть коефіцієнти лінійного рівняння y = Ax + B:" << endl;

        cout << "A (first, A не дорівнює 0) = ";
        cin >> a;

        cout << "B (second) = ";
        cin >> b;

    } while (!Init(a, b));
}

void Line::Display() const
{
    cout << "Рівняння: y = " << first << "x + " << second << endl;
}

double Line::function(double x) const
{
    return first * x + second;
}