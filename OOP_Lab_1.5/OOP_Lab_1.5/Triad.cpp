#include "Triad.h"
#include <iostream>

using namespace std;

Triad::Triad() {
    first = 0;
    second = 0;
    third = 0;
}

Triad::Triad(int f, int s, int t) {
    Init(f, s, t);
}

bool Triad::SetFirst(int value) {
    first = value;
    return true;
}

bool Triad::SetSecond(int value) {
    second = value;
    return true;
}

bool Triad::SetThird(int value) {
    third = value;
    return true;
}

bool Triad::Init(int f, int s, int t) {
    return SetFirst(f) && SetSecond(s) && SetThird(t);
}

void Triad::Read() {
    cout << "  first = ? "; cin >> first;
    cout << "  second = ? "; cin >> second;
    cout << "  third = ? "; cin >> third;
}

void Triad::Display() const {
    cout << toString();
}

string Triad::toString() const {
    stringstream sout;
    sout << "(" << first << ", " << second << ", " << third << ")";
    return sout.str();
}

bool Triad::IsGreater(const Triad& t) const {
    if (first > t.first)
        return true;
    if (first == t.first && second > t.second)
        return true;
    if (first == t.first && second == t.second && third > t.third)
        return true;
    return false;
}

bool Triad::IsLess(const Triad& t) const {
    return t.IsGreater(*this);
}

bool Triad::IsEqual(const Triad& t) const {
    return (first == t.first && second == t.second && third == t.third);
}

bool Triad::IsNotEqual(const Triad& t) const {
    return !IsEqual(t);
}