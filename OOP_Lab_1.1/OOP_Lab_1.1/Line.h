#pragma once

class Line
{
private:
    double first;
    double second;

public:
    // Методи доступу
    double GetFirst() const { return first; }
    double GetSecond() const { return second; }

    // Методи запису
    bool SetFirst(double value);
    bool SetSecond(double value);

    // Ініціалізація
    bool Init(double a, double b);

    // Введення та виведення
    void Read();
    void Display() const;

    // Обчислення значення функції
    double function(double x) const;
};