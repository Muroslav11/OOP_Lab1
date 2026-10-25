#pragma once
#include <string>

using namespace std;

class Payment
{
private:
    // =========================================================================
    // ВКЛАДЕНИЙ КЛАС MONEY
    // =========================================================================
    class Money
    {
    private:
        long hryvnias;
        unsigned char kopecks;

        // Приватний допоміжний метод
        static Money fromTotalKopecks(long long totalKopecks);

    public:
        Money();
        Money(long h, int k);

        // Гетери
        long getHryvnias() const { return hryvnias; }
        unsigned char getKopecks() const { return kopecks; }

        // Сетери
        bool setHryvnias(long value);
        bool setKopecks(int value);

        bool Init(long h, int k);
        void Read();
        void Display() const;
        string toString() const;

        // Арифметичні операції
        Money add(const Money& r) const;
        Money sub(const Money& r) const;
        double divSums(const Money& r) const;
        Money div(double val) const;
        Money mul(double val) const;

        // Операції порівняння
        bool equal(const Money& r) const;
        bool great(const Money& r) const;
        bool less(const Money& r) const;

        // Допоміжні методи
        double toDouble() const;
        long long toTotalKopecks() const;
    };

    // =========================================================================
    // ПОЛЯ КЛАСУ PAYMENT
    // =========================================================================
    string lastName;         // Прізвище
    string firstName;        // Ім'я
    string patronymic;       // По батькові
    Money rate;              // Ставка (оклад) — об'єкт вкладеного класу Money
    int yearOfEntry;         // Рік прийому на роботу
    double bonusPercent;     // Відсоток надбавки
    double incomeTaxPercent; // Прибутковий податок (%)
    int workedDays;          // Відпрацьовано днів
    int workingDays;         // Робочих днів у місяці
    Money accruedSum;        // Нарахована сума — об'єкт вкладеного класу Money
    Money withheldSum;       // Утримана сума — об'єкт вкладеного класу Money

public:
    Payment();

    // Гетери
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getPatronymic() const { return patronymic; }
    string getFullName() const { return lastName + " " + firstName + " " + patronymic; }

    // Гетери для грошових полів
    string getRateString() const { return rate.toString(); }
    string getAccruedSumString() const { return accruedSum.toString(); }
    string getWithheldSumString() const { return withheldSum.toString(); }

    int getYearOfEntry() const { return yearOfEntry; }
    double getBonusPercent() const { return bonusPercent; }
    double getIncomeTaxPercent() const { return incomeTaxPercent; }
    int getWorkedDays() const { return workedDays; }
    int getWorkingDays() const { return workingDays; }

    // Сетери
    bool setLastName(string value);
    bool setFirstName(string value);
    bool setPatronymic(string value);
    bool setFullName(string lName, string fName, string patr);

    bool setRate(long hryvnias, int kopecks);
    bool setYearOfEntry(int value);
    bool setBonusPercent(double value);
    bool setIncomeTaxPercent(double value);
    bool setWorkingDays(int value);
    bool setWorkedDays(int value);

    bool Init(string lName, string fName, string patr,
        long rateHryvnias, int rateKopecks, int yearOfEntry,
        double bonusPercent, int workedDays, int workingDays);

    void Read();
    void Display() const;
    string toString() const;

    // Обчислювальні методи
    void calculateAccruedSum();
    void calculateWithheldSum();
    string calculateNetPayString();
    int calculateExperience(int currentYear) const;
};