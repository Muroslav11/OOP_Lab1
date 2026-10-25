#include <iostream>
#include <windows.h>
#include "Payment.h"

using namespace std;

// Зовнішня функція створення об'єкта makePayment 
Payment makePayment(string lName, string fName, string patr, Money rate,
    int yearOfEntry, double bonusPercent, int workedDays, int workingDays)
{
    Payment p;
    if (!p.Init(lName, fName, patr, rate, yearOfEntry, bonusPercent, workedDays, workingDays))
    {
        cout << "Помилка: Передано некоректні параметри для створення Payment!" << endl;
    }
    return p;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== 1. ДЕМОНСТРАЦІЯ ОПЕРАЦІЙ КЛАСУ MONEY ===" << endl;
    Money m1(15000, 50);
    Money m2(3200, 75);

    cout << "Сума m1: " << m1.toString() << " грн." << endl;
    cout << "Сума m2: " << m2.toString() << " грн." << endl;

    Money sum = m1.add(m2);
    cout << "m1 + m2 = " << sum.toString() << " грн." << endl;

    Money diff = m1.sub(m2);
    cout << "m1 - m2 = " << diff.toString() << " грн." << endl;

    double ratio = m1.divSums(m2);
    cout << "Відношення m1 / m2 = " << ratio << endl;

    cout << "\n=== 2. СТВОРЕННЯ ЗВИЧАЙНОГО ОБ'ЄКТА PAYMENT ===" << endl;
    Money rate1(20000, 0);
    Payment p1;
    p1.Init("Шевченко", "Тарас", "Григорович", rate1, 2018, 15.0, 20, 22);
    p1.Display();

    int currentYear = 2026;
    cout << "Стаж роботи: " << p1.calculateExperience(currentYear) << " років." << endl;
    cout << "Сума на руки (чиста виплата): " << p1.calculateNetPay().toString() << " грн." << endl;

    cout << "\n=== 3. СТВОРЕННЯ ОБ'ЄКТА ЧЕРЕЗ makePayment ТА ВВЕДЕННЯ З КЛАВІАТУРИ ===" << endl;
    Payment p2;
    p2.Read();
    p2.Display();
    cout << "Сума на руки для p2: " << p2.calculateNetPay().toString() << " грн." << endl;

    cout << "\n=== 4. ДИНАМІЧНИЙ ОБ'ЄКТ (ВКАЗІВНИК) ===" << endl;
    Money rate2(18500, 50);
    Payment* pDyn = new Payment();
    *pDyn = makePayment("Коваленко", "Петро", "Іванович", rate2, 2021, 10.0, 22, 22);
    pDyn->Display();
    cout << "Стаж роботи (динамічний об'єкт): " << pDyn->calculateExperience(currentYear) << " років." << endl;
    delete pDyn; // Звільнення пам'яті

    cout << "\n=== 5. МАСИВ ОБ'ЄКТІВ ===" << endl;
    const int SIZE = 2;
    Payment staff[SIZE]; // Працюють конструктори за замовчуванням

    Money rStaff1(12000, 0);
    Money rStaff2(16000, 0);

    staff[0].Init("Бондаренко", "Олена", "Олексіївна", rStaff1, 2019, 5.0, 21, 22);
    staff[1].Init("Мельник", "Андрій", "Васильович", rStaff2, 2015, 20.0, 22, 22);

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nСпівробітник #" << i + 1 << ":";
        staff[i].Display();
        cout << "До видачі на руки: " << staff[i].calculateNetPay().toString() << " грн." << endl;
    }

    return 0;
}