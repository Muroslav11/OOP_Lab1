#pragma once
#include <string>
#include "Money.h"

class Payment
{
private:
    std::string lastName;       // Прізвище
    std::string firstName;      // Ім'я
    std::string patronymic;     // По батькові
    Money rate;                 // Ставка (оклад)
    int yearOfEntry;            // Рік прийому на роботу
    double bonusPercent;        // Відсоток надбавки
    double incomeTaxPercent;    // Прибутковий податок (%)
    int workedDays;             // Відпрацьовано днів
    int workingDays;            // Робочих днів у місяці
    Money accruedSum;           // Нарахована сума
    Money withheldSum;          // Утримана сума

public:
    // Конструктор за замовчуванням
    Payment();

    // Гетери
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getPatronymic() const { return patronymic; }
    std::string getFullName() const { return lastName + " " + firstName + " " + patronymic; }
    Money getRate() const { return rate; }
    int getYearOfEntry() const { return yearOfEntry; }
    double getBonusPercent() const { return bonusPercent; }
    double getIncomeTaxPercent() const { return incomeTaxPercent; }
    int getWorkedDays() const { return workedDays; }
    int getWorkingDays() const { return workingDays; }
    Money getAccruedSum() const { return accruedSum; }
    Money getWithheldSum() const { return withheldSum; }

    // Сетери з поверненням bool і суворою перевіркою
    bool setLastName(std::string value);
    bool setFirstName(std::string value);
    bool setPatronymic(std::string value);
    bool setFullName(std::string lName, std::string fName, std::string patr);

    bool setRate(Money value);
    bool setYearOfEntry(int value);
    bool setBonusPercent(double value);
    bool setIncomeTaxPercent(double value);
    bool setWorkingDays(int value);
    bool setWorkedDays(int value);

    bool Init(std::string lName, std::string fName, std::string patr,
        Money rate, int yearOfEntry, double bonusPercent,
        int workedDays, int workingDays);

    void Read();
    void Display() const;
    std::string toString() const;

    // Методи обчислень за вимогою методички
    Money calculateAccruedSum();
    Money calculateWithheldSum();
    Money calculateNetPay();
    int calculateExperience(int currentYear) const;
};