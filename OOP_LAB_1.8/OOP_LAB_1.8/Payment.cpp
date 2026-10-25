#include "Payment.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// =============================================================================
// РЕАЛІЗАЦІЯ МЕТОДІВ ВКЛАДЕНОГО КЛАСУ PAYMENT::MONEY
// =============================================================================

Payment::Money::Money() : hryvnias(0), kopecks(0) {}

Payment::Money::Money(long h, int k)
{
    Init(h, k);
}

Payment::Money Payment::Money::fromTotalKopecks(long long totalKopecks)
{
    if (totalKopecks < 0)
        totalKopecks = 0;

    long h = static_cast<long>(totalKopecks / 100);
    int k = static_cast<int>(totalKopecks % 100);

    Money result;
    result.Init(h, k);
    return result;
}

bool Payment::Money::setHryvnias(long value)
{
    if (value >= 0)
    {
        hryvnias = value;
        return true;
    }
    hryvnias = 0;
    return false;
}

bool Payment::Money::setKopecks(int value)
{
    if (value >= 0 && value < 100)
    {
        kopecks = static_cast<unsigned char>(value);
        return true;
    }
    kopecks = 0;
    return false;
}

bool Payment::Money::Init(long h, int k)
{
    bool bH = setHryvnias(h);
    bool bK = setKopecks(k);
    return bH && bK;
}

void Payment::Money::Read()
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

void Payment::Money::Display() const
{
    cout << toString();
}

string Payment::Money::toString() const
{
    stringstream sout;
    sout << hryvnias << "," << setfill('0') << setw(2) << (int)kopecks;
    return sout.str();
}

double Payment::Money::toDouble() const
{
    return hryvnias + kopecks / 100.0;
}

long long Payment::Money::toTotalKopecks() const
{
    return static_cast<long long>(hryvnias) * 100 + kopecks;
}

Payment::Money Payment::Money::add(const Money& r) const
{
    long long totalK = this->toTotalKopecks() + r.toTotalKopecks();
    return fromTotalKopecks(totalK);
}

Payment::Money Payment::Money::sub(const Money& r) const
{
    long long totalK = this->toTotalKopecks() - r.toTotalKopecks();
    return fromTotalKopecks(totalK);
}

double Payment::Money::divSums(const Money& r) const
{
    long long denominator = r.toTotalKopecks();
    if (denominator == 0)
    {
        cout << "Помилка: ділення на нульову суму!" << endl;
        return 0.0;
    }
    return static_cast<double>(this->toTotalKopecks()) / denominator;
}

Payment::Money Payment::Money::div(double val) const
{
    if (val <= 0)
    {
        cout << "Помилка: ділення на від'ємне число або нуль!" << endl;
        return Money(0, 0);
    }
    long long totalK = static_cast<long long>(round(this->toTotalKopecks() / val));
    return fromTotalKopecks(totalK);
}

Payment::Money Payment::Money::mul(double val) const
{
    if (val < 0)
    {
        cout << "Помилка: множення на від'ємне число!" << endl;
        return Money(0, 0);
    }
    long long totalK = static_cast<long long>(round(this->toTotalKopecks() * val));
    return fromTotalKopecks(totalK);
}

bool Payment::Money::equal(const Money& r) const
{
    return (hryvnias == r.hryvnias) && (kopecks == r.kopecks);
}

bool Payment::Money::great(const Money& r) const
{
    return toTotalKopecks() > r.toTotalKopecks();
}

bool Payment::Money::less(const Money& r) const
{
    return toTotalKopecks() < r.toTotalKopecks();
}

// =============================================================================
// РЕАЛІЗАЦІЯ МЕТОДІВ КЛАСУ PAYMENT
// =============================================================================

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

bool Payment::setRate(long hryvnias, int kopecks)
{
    return rate.Init(hryvnias, kopecks);
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
    long rateHryvnias, int rateKopecks, int yearOfEntry,
    double bonusPercent, int workedDays, int workingDays)
{
    bool bName = setFullName(lName, fName, patr);
    setIncomeTaxPercent(13.0);

    bool bRate = setRate(rateHryvnias, rateKopecks);
    bool bYear = setYearOfEntry(yearOfEntry);
    bool bBonus = setBonusPercent(bonusPercent);
    bool bWorking = setWorkingDays(workingDays);
    bool bWorked = setWorkedDays(workedDays);

    calculateAccruedSum();
    calculateWithheldSum();

    return bName && bRate && bYear && bBonus && bWorking && bWorked;
}

void Payment::calculateAccruedSum()
{
    Money base = rate.mul(static_cast<double>(workedDays) / workingDays);
    accruedSum = base.mul(1.0 + bonusPercent / 100.0);
}

void Payment::calculateWithheldSum()
{
    Money pf = accruedSum.mul(0.01);
    Money tax = accruedSum.mul(incomeTaxPercent / 100.0);

    withheldSum = pf.add(tax);
}

string Payment::calculateNetPayString()
{
    Money net = accruedSum.sub(withheldSum);
    return net.toString();
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
    long rateH;
    int rateK;
    int year, worked, working;
    double bonus;

    cout << "\n--- Введення даних працівника ---" << endl;
    cout << "Прізвище: "; cin >> lName;
    cout << "Ім'я: "; cin >> fName;
    cout << "По батькові: "; cin >> patr;

    cout << "Ставка (оклад):" << endl;
    Money tempRate;
    tempRate.Read();
    rateH = tempRate.getHryvnias();
    rateK = tempRate.getKopecks();

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
    } while (!Init(lName, fName, patr, rateH, rateK, year, bonus, worked, working));
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