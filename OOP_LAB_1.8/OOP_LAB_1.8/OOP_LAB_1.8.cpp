#include <iostream>
#include <windows.h>
#include "Payment.h"

using namespace std;

Payment makePayment(string lName, string fName, string patr, long rateHryvnias,
    int rateKopecks, int yearOfEntry, double bonusPercent,
    int workedDays, int workingDays)
{
    Payment p;
    if (!p.Init(lName, fName, patr, rateHryvnias, rateKopecks, yearOfEntry, bonusPercent, workedDays, workingDays))
    {
        cout << "Помилка: Передано некоректні параметри для створення Payment!" << endl;
    }
    return p;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== 1. СТВОРЕННЯ ЗВИЧАЙНОГО ОБ'ЄКТА PAYMENT ===" << endl;
    Payment p1;
    p1.Init("Шевченко", "Тарас", "Григорович", 20000, 0, 2018, 15.0, 20, 22);
    p1.Display();

    int currentYear = 2026;
    cout << "Стаж роботи: " << p1.calculateExperience(currentYear) << " років." << endl;
    cout << "Сума на руки (чиста виплата): " << p1.calculateNetPayString() << " грн." << endl;

    cout << "\n=== 2. СТВОРЕННЯ ОБ'ЄКТА ЧЕРЕЗ makePayment ТА ВВЕДЕННЯ З КЛАВІАТУРИ ===" << endl;
    Payment p2;
    p2.Read();
    p2.Display();
    cout << "Сума на руки для p2: " << p2.calculateNetPayString() << " грн." << endl;

    cout << "\n=== 3. ДИНАМІЧНИЙ ОБ'ЄКТ (ВКАЗІВНИК) ===" << endl;
    Payment* pDyn = new Payment();
    *pDyn = makePayment("Коваленко", "Петро", "Іванович", 18500, 50, 2021, 10.0, 22, 22);
    pDyn->Display();
    cout << "Стаж роботи (динамічний об'єкт): " << pDyn->calculateExperience(currentYear) << " років." << endl;
    delete pDyn;

    cout << "\n=== 4. МАСИВ ОБ'ЄКТІВ ===" << endl;
    const int SIZE = 2;
    Payment staff[SIZE];

    staff[0].Init("Бондаренко", "Олена", "Олексіївна", 12000, 0, 2019, 5.0, 21, 22);
    staff[1].Init("Мельник", "Андрій", "Васильович", 16000, 0, 2015, 20.0, 22, 22);

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nСпівробітник #" << i + 1 << ":";
        staff[i].Display();
        cout << "До видачі на руки: " << staff[i].calculateNetPayString() << " грн." << endl;
    }

    return 0;
}