#include <iostream>
#include <Windows.h>
#include "Polynomial.h"

using namespace std;

void demonstrateObjectCreation()
{
    cout << "\n=== Демонстрація способів створення об'єктів та масивів ===" << endl;

    // 1. Статичний об'єкт
    Polynomial p1;
    cout << "1. Статичний об'єкт за замовчуванням: ";
    p1.Display();

    // 2. Створення через фабричну функцію makePolynomial
    double c1[] = { 1.0, 2.0, 3.0 };
    Polynomial p2 = makePolynomial(2, c1);
    cout << "2. Об'єкт через makePolynomial: ";
    p2.Display();

    // 3. Динамічний об'єкт локальний масив без витоків пам'яті
    double cDynamic[] = { 5.0, 4.0 };
    Polynomial* pDynamic = new Polynomial();
    pDynamic->Init(1, cDynamic);
    cout << "3. Динамічний об'єкт (*pDynamic): ";
    pDynamic->Display();
    delete pDynamic;

    // 4. Статичний масив об'єктів
    const int ARR_SIZE = 2;
    Polynomial arrStatic[ARR_SIZE];
    arrStatic[0].Init(2, c1);
    arrStatic[1].Init(1, cDynamic);
    cout << "4. Статичний масив об'єктів:" << endl;
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        cout << "   arrStatic[" << i << "]: ";
        arrStatic[i].Display();
    }

    // 5. Динамічний масив об'єктів
    Polynomial* arrDynamic = new Polynomial[ARR_SIZE];
    arrDynamic[0].Init(1, cDynamic);
    arrDynamic[1].Init(2, c1);
    cout << "5. Динамічний масив об'єктів:" << endl;
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        cout << "   arrDynamic[" << i << "]: ";
        arrDynamic[i].Display();
    }
    delete[] arrDynamic;

    cout << "===========================================================\n" << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    demonstrateObjectCreation();

    Polynomial A, B, C;
    int choice;

    do
    {
        cout << "\n------------ МЕНЮ РОБОТИ З МНОГОЧЛЕНАМИ ------------" << endl;
        cout << "1. Ввести многочлен A (Read)" << endl;
        cout << "2. Ввести многочлен B (Read)" << endl;
        cout << "3. Вивести поточні многочлени (Display / toString)" << endl;
        cout << "4. Обчислити значення A(x) для заданого x" << endl;
        cout << "5. Додавання: C = A + B" << endl;
        cout << "6. Віднімання: C = A - B" << endl;
        cout << "7. Множення: C = A * B" << endl;
        cout << "8. Перевірка методів доступу (getCoeff / setCoeff) для A" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nВведення A:" << endl;
            A.Read();
            break;

        case 2:
            cout << "\nВведення B:" << endl;
            B.Read();
            break;

        case 3:
            cout << "\nМногочлен A: ";
            A.Display();
            cout << "Многочлен B: ";
            B.Display();
            cout << "Останній C (toString): " << C.toString() << endl;
            break;

        case 4:
        {
            double x;
            cout << "\nВведіть значення x: ";
            cin >> x;
            cout << "A(" << x << ") = " << A.evaluate(x) << endl;
            break;
        }

        case 5:
            C = A.add(B);
            cout << "\nРезультат C = A + B:\n";
            C.Display();
            break;

        case 6:
            C = A.subtract(B);
            cout << "\nРезультат C = A - B:\n";
            C.Display();
            break;

        case 7:
            C = A.multiply(B);
            cout << "\nРезультат C = A * B:\n";
            C.Display();
            break;

        case 8:
        {
            cout << "\nСтепінь A: " << A.getDegree() << endl;
            int idx;
            double val;
            cout << "Введіть індекс коефіцієнта: ";
            cin >> idx;
            cout << "Введіть нове значення: ";
            cin >> val;
            if (A.setCoeff(idx, val))
            {
                cout << "Успішно змінено! Новий вигляд A: ";
                A.Display();
            }
            break;
        }

        case 0:
            cout << "Завершення роботи." << endl;
            break;

        default:
            cout << "Некоректний вибір! Спробуйте ще раз." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}