#include "Line.h"
#include <iostream>
#include <windows.h>

using namespace std;

Line makeLine(double a, double b)
{
    Line line;

    if (!line.Init(a, b))
    {
        cout << "Помилкові аргументи для Init! Коефіцієнт A не може бути нулем." << endl;
        exit(1);
    }

    return line;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Line line1;

    line1.Read();
    line1.Display();

    double x;

    cout << "Введіть значення x: ";
    cin >> x;

    cout << "Значення функції y = " << line1.function(x) << endl << endl;

    double a, b;

    cout << "Введіть коефіцієнти для нової прямої:" << endl;

    cout << "A = ";
    cin >> a;

    cout << "B = ";
    cin >> b;

    Line line2 = makeLine(a, b);

    line2.Display();

    cout << "Введіть значення x: ";
    cin >> x;

    cout << "Значення функції y = " << line2.function(x) << endl;

    return 0;
}