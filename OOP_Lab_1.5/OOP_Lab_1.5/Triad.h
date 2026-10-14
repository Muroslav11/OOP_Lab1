#pragma once
#include <string>
#include <sstream>

using namespace std;

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

    bool Init(int first, int second, int third);
    void Read();
    void Display() const;
    string toString() const;

    bool IsGreater(const Triad& t) const;
    bool IsLess(const Triad& t) const;
    bool IsEqual(const Triad& t) const;
    bool IsNotEqual(const Triad& t) const;
};