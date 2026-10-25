#include "Payment.h"
#include <iostream>
#include <sstream>

using namespace std;

Payment::Payment()
    : lastName("Невідомо"), firstName("Невідомо"), patronymic("Невідомо"),
    yearOfEntry(2020), bonusPercent(0.0), incomeTaxPercent(13.0),
    workedDays(0), workingDays(22)
{
    rate.Init(0, 0);
    accruedSum.Init(0, 0);
    withheldSum.Init(0, 0);
}

bool Payment::setLastName(string value)
{
    if (!value.empty())
    {
        lastName = value;
        return true;
    }
    lastName = "Невідомо";
    return false;
}

bool Payment::setFirstName(string value)
{
    if (!value.empty())
    {
        firstName = value;
        return true;
    }
    firstName = "Невідомо";
    return false;
}

bool Payment::setPatronymic(string value)
{
    if (!value.empty())
    {
        patronymic = value;
        return true;
    }
    patronymic = "Невідомо";
    return false;
}

bool Payment::setFullName(string lName, string fName, string patr)
{
    bool bL = setLastName(lName);
    bool bF = setFirstName(fName);
    bool bP = setPatronymic(patr);
    return bL && bF && bP;
}

bool Payment::setRate(Money value)
{
    if (value.toDouble() >= 0)
    {
        rate = value;
        return true;
    }
    rate.Init(0, 0);
    return false;
}

bool Payment::setYearOfEntry(int value)
{
    if (value >= 1900 && value <= 2026)
    {
        yearOfEntry = value;
        return true;
    }
    yearOfEntry = 2020;
    return false;
}

bool Payment::setBonusPercent(double value)
{
    if (value >= 0)
    {
        bonusPercent = value;
        return true;
    }
    bonusPercent = 0;
    return false;
}

bool Payment::setIncomeTaxPercent(double value)
{
    if (value >= 0 && value <= 100)
    {
        incomeTaxPercent = value;
        return true;
    }
    incomeTaxPercent = 13.0;
    return false;
}

bool Payment::setWorkingDays(int value)
{
    if (value >= 1 && value <= 31)
    {
        workingDays = value;
        if (workedDays > workingDays)
            workedDays = workingDays;
        return true;
    }
    workingDays = 22;
    workedDays = 0;
    return false;
}

bool Payment::setWorkedDays(int value)
{
    if (value >= 0 && value <= workingDays)
    {
        workedDays = value;
        return true;
    }
    if (value > workingDays)
        workedDays = workingDays;
    else
        workedDays = 0;
    return false;
}

bool Payment::Init(string lName, string fName, string patr,
    Money rate, int yearOfEntry, double bonusPercent,
    int workedDays, int workingDays)
{
    bool bName = setFullName(lName, fName, patr);
    setIncomeTaxPercent(13.0); // 13% за умовою варіанту 10

    bool bRate = setRate(rate);
    bool bYear = setYearOfEntry(yearOfEntry);
    bool bBonus = setBonusPercent(bonusPercent);
    bool bWorking = setWorkingDays(workingDays);
    bool bWorked = setWorkedDays(workedDays);

    calculateAccruedSum();
    calculateWithheldSum();

    return bName && bRate && bYear && bBonus && bWorking && bWorked;
}

Money Payment::calculateAccruedSum()
{
    // Оклад / робочі_дні * відпрацьовані_дні + надбавка
    Money base = rate.mul(static_cast<double>(workedDays) / workingDays);
    accruedSum = base.mul(1.0 + bonusPercent / 100.0);
    return accruedSum;
}

Money Payment::calculateWithheldSum()
{
    // 1% відрахування до пенсійного фонду від нарахованої суми
    Money pf = accruedSum.mul(0.01);
    // 13% прибутковий податок від нарахованої суми
    Money tax = accruedSum.mul(incomeTaxPercent / 100.0);

    withheldSum = pf.add(tax);
    return withheldSum;
}

Money Payment::calculateNetPay()
{
    return accruedSum.sub(withheldSum);
}

int Payment::calculateExperience(int currentYear) const
{
    if (currentYear >= yearOfEntry)
        return currentYear - yearOfEntry;
    return 0;
}

void Payment::Read()
{
    string lName, fName, patr;
    Money r;
    int year, worked, working;
    double bonus;

    cout << "\n--- Введення даних працівника ---" << endl;
    cout << "Прізвище: "; cin >> lName;
    cout << "Ім'я: "; cin >> fName;
    cout << "По батькові: "; cin >> patr;

    cout << "Ставка (оклад):" << endl;
    r.Read();

    do
    {
        cout << "Рік прийому на роботу (1900-2026): ";
        while (!(cin >> year))
        {
            cout << "Помилка! Введіть числовий рік (1900-2026): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Відсоток надбавки (%): ";
        while (!(cin >> bonus))
        {
            cout << "Помилка! Введіть додатний відсоток: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Кількість робочих днів у місяці (1..31): ";
        while (!(cin >> working))
        {
            cout << "Помилка! Введіть ціле число (1..31): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Кількість відпрацьованих днів (0.." << working << "): ";
        while (!(cin >> worked))
        {
            cout << "Помилка! Введіть ціле число (0.." << working << "): ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!Init(lName, fName, patr, r, year, bonus, worked, working));
}

void Payment::Display() const
{
    cout << toString();
}

string Payment::toString() const
{
    stringstream sout;
    sout << "\n==========================================" << endl;
    sout << "ПІБ: " << getFullName() << endl;
    sout << "Ставка: " << rate.toString() << " грн." << endl;
    sout << "Рік прийому на роботу: " << yearOfEntry << endl;
    sout << "Надбавка: " << bonusPercent << "%" << endl;
    sout << "Відпрацьовано днів: " << workedDays << " з " << workingDays << endl;
    sout << "Нарахована сума: " << accruedSum.toString() << " грн." << endl;
    sout << "Утримана сума: " << withheldSum.toString() << " грн." << endl;
    sout << "==========================================" << endl;
    return sout.str();
}