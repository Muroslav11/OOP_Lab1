//////////////////////////////////////////////////////////////////////////////
// OOP_Lab_1.3.cpp
// головний файл проекту – функція main
//////////////////////////////////////////////////////////////////////////////

#include "LongLong.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // 1. Створення та ініціалізація об'єктів
    cout << "=== 1. Робота з окремими об'єктами ===" << endl;
    LongLong a, b, c;
    a.Init(0, 100);
    b.Init(0, 200);

    cout << "a: "; a.Display();
    cout << "b: "; b.Display();

    // 2. Виклик дружніх операцій додавання та множення 
    c = Add(a, b);
    cout << "\nAdd(a, b) -> c = ";
    c.Display();

    LongLong d = Multiply(a, b);
    cout << "Multiply(a, b) -> d = ";
    d.Display();

    // 3. Операції порівняння
    cout << "\n=== 2. Перевірка операцій порівняння ===" << endl;
    cout << "Less(a, b): " << (Less(a, b) ? "true" : "false") << endl;
    cout << "NotLess(a, b): " << (NotLess(a, b) ? "true" : "false") << endl;
    cout << "Greater(a, b): " << (Greater(a, b) ? "true" : "false") << endl;

    // 4. Введення з клавіатури
    cout << "\n=== 3. Введення з клавіатури Read() ===" << endl;
    LongLong inputObj;
    inputObj.Read();
    cout << "Введений об'єкт: ";
    inputObj.Display();

    // 5. Демонстрація статичного масиву об'єктів
    cout << "\n=== 4. Статичний масив об'єктів ===" << endl;
    const int N = 3;
    LongLong arrStatic[N];
    for (int i = 0; i < N; i++)
    {
        arrStatic[i].Init(i, (i + 1) * 50);
        cout << "arrStatic[" << i << "] = ";
        arrStatic[i].Display();
    }

    // 6. Демонстрація динамічного масиву об'єктів 
    cout << "\n=== 5. Динамічний масив об'єктів ===" << endl;
    int M = 2;
    LongLong* arrDynamic = new LongLong[M];
    arrDynamic[0].Init(1, 10);
    arrDynamic[1].Init(2, 20);

    for (int i = 0; i < M; i++)
    {
        cout << "arrDynamic[" << i << "] = " << arrDynamic[i].toString() << endl;
    }

    delete[] arrDynamic;

    return 0;
}