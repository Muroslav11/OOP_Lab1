#include "Polynomial.h"
#include <iostream>
#include <sstream>

using namespace std;

Polynomial::Polynomial()
{
    degree = 0;
    coeff = new double[1];
    coeff[0] = 0.0;
}

Polynomial::Polynomial(const Polynomial& other)
{
    degree = other.degree;
    coeff = new double[degree + 1];
    for (int i = 0; i <= degree; ++i)
    {
        coeff[i] = other.coeff[i];
    }
}

Polynomial::~Polynomial()
{
    delete[] coeff;
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this != &other)
    {
        delete[] coeff;
        degree = other.degree;
        coeff = new double[degree + 1];
        for (int i = 0; i <= degree; ++i)
        {
            coeff[i] = other.coeff[i];
        }
    }
    return *this;
}

double Polynomial::getCoeff(int index) const
{
    if (index >= 0 && index <= degree)
    {
        return coeff[index];
    }
    return 0.0;
}

bool Polynomial::setDegree(int newDegree)
{
    if (newDegree >= 0)
    {
        double* temp = new double[newDegree + 1];
        for (int i = 0; i <= newDegree; ++i)
        {
            temp[i] = 0.0;
        }

        int minDeg;
        if (degree < newDegree)
        {
            minDeg = degree;
        }
        else
        {
            minDeg = newDegree;
        }

        for (int i = 0; i <= minDeg; ++i)
        {
            temp[i] = coeff[i];
        }

        delete[] coeff;
        coeff = temp;
        degree = newDegree;
        return true;
    }
    else
    {
        cerr << "Помилка: степінь многочлена не може бути від'ємним!" << endl;
        return false;
    }
}

bool Polynomial::setCoeff(int index, double value)
{
    if (index >= 0 && index <= degree)
    {
        coeff[index] = value;
        return true;
    }
    else
    {
        cerr << "Помилка: вихід індексу коефіцієнта за межі!" << endl;
        return false;
    }
}

// Сетер усього масиву коефіцієнтів із валідацією
bool Polynomial::setCoefficients(const double* newCoeffs, int newDegree)
{
    if (newDegree < 0 || newCoeffs == nullptr)
    {
        return false;
    }

    delete[] coeff;
    degree = newDegree;
    coeff = new double[degree + 1];
    for (int i = 0; i <= degree; ++i)
    {
        coeff[i] = newCoeffs[i];
    }
    return true;
}

// За правилом методички: перевірка в сетері, Init повторно використовує її
bool Polynomial::Init(int n, const double* coeffs)
{
    return setCoefficients(coeffs, n);
}

void Polynomial::Read()
{
    int n;
    do
    {
        cout << "Введіть степінь многочлена n (n >= 0): ";
        cin >> n;
        if (n < 0)
        {
            cout << "Помилка! Степінь не може бути від'ємним." << endl;
        }
    } while (n < 0);

    double* arr = new double[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }

    Init(n, arr);
    delete[] arr; // Очищення тимчасового буфера після заповнення об'єкта
}

//  P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
string Polynomial::toString() const
{
    stringstream sout;
    sout << "P(x) = " << coeff[0];
    for (int i = 1; i <= degree; ++i)
    {
        sout << " + (" << coeff[i] << ")*x^" << i;
    }
    return sout.str();
}

void Polynomial::Display() const
{
    cout << toString() << endl;
}

double Polynomial::evaluate(double x) const
{
    double result = coeff[degree];
    for (int i = degree - 1; i >= 0; --i)
    {
        result = result * x + coeff[i];
    }
    return result;
}

Polynomial Polynomial::add(const Polynomial& other) const
{
    int maxDeg;
    if (degree > other.degree)
    {
        maxDeg = degree;
    }
    else
    {
        maxDeg = other.degree;
    }

    double* resCoeffs = new double[maxDeg + 1];
    for (int i = 0; i <= maxDeg; ++i)
    {
        resCoeffs[i] = 0.0;
    }

    for (int i = 0; i <= degree; ++i)
    {
        resCoeffs[i] += coeff[i];
    }
    for (int i = 0; i <= other.degree; ++i)
    {
        resCoeffs[i] += other.coeff[i];
    }

    Polynomial res;
    res.Init(maxDeg, resCoeffs);
    delete[] resCoeffs;
    return res;
}

Polynomial Polynomial::subtract(const Polynomial& other) const
{
    int maxDeg;
    if (degree > other.degree)
    {
        maxDeg = degree;
    }
    else
    {
        maxDeg = other.degree;
    }

    double* resCoeffs = new double[maxDeg + 1];
    for (int i = 0; i <= maxDeg; ++i)
    {
        resCoeffs[i] = 0.0;
    }

    for (int i = 0; i <= degree; ++i)
    {
        resCoeffs[i] += coeff[i];
    }
    for (int i = 0; i <= other.degree; ++i)
    {
        resCoeffs[i] -= other.coeff[i];
    }

    Polynomial res;
    res.Init(maxDeg, resCoeffs);
    delete[] resCoeffs;
    return res;
}

Polynomial Polynomial::multiply(const Polynomial& other) const
{
    int newDeg = degree + other.degree;
    double* resCoeffs = new double[newDeg + 1];
    for (int i = 0; i <= newDeg; ++i)
    {
        resCoeffs[i] = 0.0;
    }

    for (int i = 0; i <= degree; ++i)
    {
        for (int j = 0; j <= other.degree; ++j)
        {
            resCoeffs[i + j] += coeff[i] * other.coeff[j];
        }
    }

    Polynomial res;
    res.Init(newDeg, resCoeffs);
    delete[] resCoeffs;
    return res;
}

Polynomial makePolynomial(int n, const double* coeffs)
{
    Polynomial p;
    if (!p.Init(n, coeffs))
    {
        cout << "Помилка передачі аргументів до makePolynomial!" << endl;
        exit(1);
    }
    return p;
}