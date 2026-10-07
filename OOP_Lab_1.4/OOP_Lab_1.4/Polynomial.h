#pragma once
#include <string>

using namespace std;

class Polynomial
{
private:
    int degree;       // степінь многочлена n (degree >= 0)
    double* coeff;    // динамічний масив коефіцієнтів a0, a1, ..., an

public:
    Polynomial();
    Polynomial(const Polynomial& other);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& other);

    // Методи доступу 
    int getDegree() const { return degree; }
    double getCoeff(int index) const;
    bool setDegree(int newDegree);
    bool setCoeff(int index, double value);
    bool setCoefficients(const double* newCoeffs, int newDegree);

    // Обов'язкові методи за методичними вказівками
    bool Init(int n, const double* coeffs);
    void Read();
    void Display() const;
    string toString() const;

    // Специфічні операції
    double evaluate(double x) const;
    Polynomial add(const Polynomial& other) const;
    Polynomial subtract(const Polynomial& other) const;
    Polynomial multiply(const Polynomial& other) const;
};

// Зовнішня функція фабричного створення 
Polynomial makePolynomial(int n, const double* coeffs);