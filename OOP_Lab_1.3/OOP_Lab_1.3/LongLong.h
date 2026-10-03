//////////////////////////////////////////////////////////////////////////////
// LongLong.h
// заголовний файл – визначення класу
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

using namespace std;

class LongLong
{
private:
    long high; // старша 32-розрядна частина
    long low;  // молодша 32-розрядна частина

public:
    // Конструктор за замовчуванням
    LongLong();

    // Методи доступу (зчитування та запису)
    long GetHigh() const { return high; }
    long GetLow() const { return low; }

    bool SetHigh(long value);
    bool SetLow(long value);

    // Обов'язкові методи
    bool Init(long h, long l);
    void Read();
    void Display() const;
    string toString() const;

    // Допоміжні методи для бітової композиції 64-розрядного числа
    void FromInt64(long long value);
    long long ToInt64() const;

    // Арифметичні операції як дружні функції 
    friend LongLong Add(const LongLong& l, const LongLong& r);
    friend LongLong Multiply(const LongLong& l, const LongLong& r);

    // Операції порівняння як дружні функції
    friend bool Less(const LongLong& l, const LongLong& r);
    friend bool NotLess(const LongLong& l, const LongLong& r);
    friend bool Greater(const LongLong& l, const LongLong& r);
};