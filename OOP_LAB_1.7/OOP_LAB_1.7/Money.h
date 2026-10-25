#pragma once
#include <string>

class Money
{
private:
    long hryvnias;
    unsigned char kopecks;

    // Приватний допоміжний метод перетворення копійок у об'єкт Money
    static Money fromTotalKopecks(long long totalKopecks);

public:
    // Конструктори
    Money();
    Money(long h, int k);

    // Гетери
    long getHryvnias() const { return hryvnias; }
    unsigned char getKopecks() const { return kopecks; }

    // Сетери з жорсткою перевіркою
    bool setHryvnias(long value);
    bool setKopecks(int value);

    bool Init(long h, int k);
    void Read();
    void Display() const;
    std::string toString() const;

    // Арифметичні операції за умовою варіанту 10
    Money add(const Money& r) const;
    Money sub(const Money& r) const;
    double divSums(const Money& r) const; // Повертає безрозмірне число (double)
    Money div(double val) const;
    Money mul(double val) const;

    // Операції порівняння
    bool equal(const Money& r) const;
    bool great(const Money& r) const;
    bool less(const Money& r) const;

    // Допоміжні методи для внутрішніх та зовнішніх розрахунків
    double toDouble() const;
    long long toTotalKopecks() const;
};