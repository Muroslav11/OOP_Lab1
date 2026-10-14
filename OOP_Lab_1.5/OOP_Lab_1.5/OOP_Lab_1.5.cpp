#include <iostream>
#include "Date.h"
#include <Windows.h>

using namespace std;

Date makeDate(int year, int month, int day) {
    Date d;
    if (!d.Init(year, month, day)) {
        cout << "Попередження: передано невалідну дату. Встановлено дефолтне значення." << endl;
    }
    return d;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    cout << "=== ДЕМОНСТРАЦІЯ РОБОТИ ПРОГРАМИ ===" << endl << endl;

    // 1. Демонстрація роботи з класом Triad окремо
    cout << "--- 1. Клас Triad ---" << endl;
    Triad t1(10, 20, 30);
    Triad t2;
    t2.Init(10, 25, 5);
    cout << "t1 = "; t1.Display(); cout << endl;
    cout << "t2 = "; t2.Display(); cout << endl;
    cout << "t1 більша за t2: " << (t1.IsGreater(t2) ? "true" : "false") << endl << endl;

    // 2. Різні способи створення об'єктів Date
    cout << "--- 2. Способи створення об'єктів Date ---" << endl;
    Date d1(2026, 10, 14); // Статичний об'єкт
    cout << "d1 (статичний): "; d1.Display();

    Date* d2 = new Date(2024, 2, 29); // Динамічний об'єкт через new
    cout << "d2 (динамічний): "; d2->Display();

    Date d3 = makeDate(2025, 12, 31); // Через фабричну функцію
    cout << "d3 (makeDate): "; d3.Display();
    cout << endl;

    // 3. Створення масиву об'єктів
    cout << "--- 3. Масив об'єктів Date ---" << endl;
    Date datesArr[3] = {
        Date(2021, 5, 12),
        Date(2023, 8, 19),
        Date(2026, 1, 1)
    };
    for (int i = 0; i < 3; i++) {
        cout << "datesArr[" << i << "] = ";
        datesArr[i].Display();
    }
    cout << endl;

    // 4. Перевірка безпечних сетерів з валідацією
    cout << "--- 4. Перевірка сетерів ---" << endl;
    cout << "Поточна дата d1: " << d1.toString() << endl;
    bool changeRes = d1.SetMonth(2);
    cout << "Зміна місяця на 2 (2026-02-14): " << (changeRes ? "успіх" : "помилка") << endl;
    bool badRes = d1.SetDay(30); // 30 лютого не існує
    cout << "Спроба встановити день 30 у лютому: " << (badRes ? "успіх" : "помилка") << endl;
    cout << "Стан d1 захищено: " << d1.toString() << endl << endl;

    // 5. Введення даних через Read()
    cout << "--- 5. Введення дати з клавіатури ---" << endl;
    Date d4;
    d4.Read();
    cout << "Введена дата d4 = "; d4.Display();
    cout << endl;

    // 6. Повний набір методів порівняння
    cout << "--- 6. Порівняння дат (d1 та d4) ---" << endl;
    cout << "d1 == d4 : " << (d1.IsEqual(d4) ? "true" : "false") << endl;
    cout << "d1 != d4 : " << (d1.IsNotEqual(d4) ? "true" : "false") << endl;
    cout << "d1 > d4  : " << (d1.IsGreater(d4) ? "true" : "false") << endl;
    cout << "d1 < d4  : " << (d1.IsLess(d4) ? "true" : "false") << endl;
    cout << "d1 >= d4 : " << (d1.IsGreaterOrEqual(d4) ? "true" : "false") << endl;
    cout << "d1 <= d4 : " << (d1.IsLessOrEqual(d4) ? "true" : "false") << endl;

    // Звільнення динамічної пам'яті
    delete d2;

    return 0;
}