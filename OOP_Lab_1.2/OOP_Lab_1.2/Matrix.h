//////////////////////////////////////////////////////////////////////////////
// Matrix.h
// заголовний файл – визначення класу
//////////////////////////////////////////////////////////////////////////////

#pragma once

class Matrix
{
private:
    int** data;    // зв'язок з динамічним двовимірним масивом
    int rows;      // кількість рядків
    int cols;      // кількість стовпців
    int state;     // змінна стану (0 - OK, 1 - пам'ять, 2 - межі, 3 - розмірності)

    void freeMemory(); // допоміжний метод для безпечного звільнення пам'яті

public:
    // Конструктор за замовчуванням
    Matrix();

    // Методи зчитування значень полів (константні)
    int** getData() const { return data; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getState() const { return state; }

    // Методи запису значень полів із валідацією
    bool setRows(int value);
    bool setCols(int value);
    bool setState(int value);

    // Обов'язкові методи
    bool Init(int rows, int cols);
    void Read();
    void Display() const;

    // Специфічні методи за варіантом
    int getElement(int i, int j);
    void Multiply(int number);

    // Деструктор
    ~Matrix();
};

// Зовнішня функція створення об'єкта
Matrix makeMatrix(int rows, int cols);