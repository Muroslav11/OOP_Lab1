//////////////////////////////////////////////////////////////////////////////
// Matrix.cpp
// файл реалізації – реалізація методів класу
//////////////////////////////////////////////////////////////////////////////

#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Конструктор за замовчуванням
Matrix::Matrix()
{
    data = nullptr;
    rows = 0;
    cols = 0;
    state = 0;
}

// Допоміжний метод звільнення виділеної пам'яті
void Matrix::freeMemory()
{
    if (data != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

// Метод запису кількості рядків
bool Matrix::setRows(int value)
{
    if (value > 0)
    {
        rows = value;
        return true;
    }
    else
    {
        rows = 0;
        state = 3; // помилка невідповідності розмірностей
        return false;
    }
}

// Метод запису кількості стовпців
bool Matrix::setCols(int value)
{
    if (value > 0)
    {
        cols = value;
        return true;
    }
    else
    {
        cols = 0;
        state = 3; // помилка невідповідності розмірностей
        return false;
    }
}

// Метод запису стану
bool Matrix::setState(int value)
{
    if (value >= 0 && value <= 3)
    {
        state = value;
        return true;
    }
    else
    {
        return false;
    }
}

// Метод ініціалізації полів
bool Matrix::Init(int rows, int cols)
{
    // Звільняємо попередню пам'ять у разі повторного виклику Init
    freeMemory();

    state = 0;

    // Перевірка через сетери (вимогу контролю аргументів неможливо обійти)
    if (!setRows(rows) || !setCols(cols))
    {
        return false;
    }

    // Виділення динамічної пам'яті під масив вказівників
    data = new (nothrow) int* [this->rows];
    if (data == nullptr)
    {
        state = 1; // помилка виділення пам'яті
        this->rows = 0;
        this->cols = 0;
        return false;
    }

    // Виділення динамічної пам'яті для кожного рядка
    for (int i = 0; i < this->rows; i++)
    {
        data[i] = new (nothrow) int[this->cols];
        if (data[i] == nullptr)
        {
            state = 1; // помилка виділення пам'яті

            // Очищення вже виділених рядків
            for (int j = 0; j < i; j++)
            {
                delete[] data[j];
            }
            delete[] data;
            data = nullptr;
            this->rows = 0;
            this->cols = 0;
            return false;
        }
    }

    // Ініціалізація нулями
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            data[i][j] = 0;
        }
    }

    return true;
}

// Введення значень з клавіатури
void Matrix::Read()
{
    int r;
    int c;

    do
    {
        cout << " rows =  ";
        cin >> r;
        cout << " cols =  ";
        cin >> c;

        if (r <= 0 || c <= 0)
        {
            cout << "Помилка: розмірності мають бути більшими за 0!" << endl;
        }
    } while (!Init(r, c));

    cout << "Введіть елементи матриці (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " data[" << i << "][" << j << "] = ? ";
            cin >> data[i][j];
        }
    }
}

// Виведення матриці на екран
void Matrix::Display() const
{
    cout << " rows = " << rows << endl;
    cout << " cols = " << cols << endl;
    cout << " state = " << state << endl;

    if (data == nullptr || rows == 0 || cols == 0)
    {
        cout << "Матриця порожня." << endl;
        return;
    }

    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << data[i][j] << " ";
        }
        cout << endl;
    }
}

// Метод повернення значення елемента за індексами (i, j)
int Matrix::getElement(int i, int j)
{
    if (data != nullptr && i >= 0 && i < rows && j >= 0 && j < cols)
    {
        state = 0;
        return data[i][j];
    }
    else
    {
        state = 2; // помилка виходу за межі масиву
        cout << "[Помилка]: Спроба виходу за межі масиву!" << endl;
        return 0;
    }
}

// Множення матриці на число
void Matrix::Multiply(int number)
{
    if (data == nullptr)
    {
        state = 3;
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] *= number;
        }
    }
}

// Деструктор
Matrix::~Matrix()
{
    freeMemory();
}

// Зовнішня функція makeMatrix
Matrix makeMatrix(int rows, int cols)
{
    Matrix m;

    if (!m.Init(rows, cols))
    {
        cout << "Критична помилка: передано некоректні розмірності матриці!" << endl;
        exit(1); // Завершення роботи за вимогою завдання
    }

    return m;
}