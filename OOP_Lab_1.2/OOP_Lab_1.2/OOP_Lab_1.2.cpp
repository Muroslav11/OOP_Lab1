//////////////////////////////////////////////////////////////////////////////
// OOP_Lab_1.2.cpp
// головний файл проекту – функція main
//////////////////////////////////////////////////////////////////////////////

#include "Matrix.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // 1. Створення об'єкта через метод Read()
    cout << "=== Тестування створення через Read() ===" << endl;
    Matrix m1;
    m1.Read();
    cout << endl;
    m1.Display();

    // Перевірка методу getElement
    int rIndex, cIndex;
    cout << "\nВведіть індекси для отримання елемента (i j): ";
    cin >> rIndex >> cIndex;
    int val = m1.getElement(rIndex, cIndex);
    if (m1.getState() == 0)
    {
        cout << "m1[" << rIndex << "][" << cIndex << "] = " << val << endl;
    }
    cout << "Поточний state: " << m1.getState() << endl;

    // Перевірка множення на число
    int number;
    cout << "\nВведіть число для множення матриці: ";
    cin >> number;
    m1.Multiply(number);
    cout << "\nМатриця після множення на " << number << ":" << endl;
    m1.Display();

    // 2. Створення об'єкта через makeMatrix()
    cout << "\n=== Тестування створення через makeMatrix() ===" << endl;
    Matrix m2 = makeMatrix(2, 3);
    cout << "Матриця m2 (2x3), створена функцією makeMatrix:" << endl;
    m2.Display();

    // Демонстрація фіксації виходу за межі діапазону (state = 2)
    cout << "\nЗвернення до неіснуючого елемента m2[10][10]:" << endl;
    m2.getElement(10, 10);
    cout << "Стан після виходу за межі state = " << m2.getState() << endl;

    return 0;
}