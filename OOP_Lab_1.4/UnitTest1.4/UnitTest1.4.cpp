#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.4/Polynomial.h"
#include "../OOP_Lab_1.4/Polynomial.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPolynomial
{
    TEST_CLASS(UnitTestPolynomial)
    {
    public:

        // Тест 1: Перевірка обчислення значення многочлена P(x)
        TEST_METHOD(TestEvaluate)
        {
            // P(x) = 1 + 2*x + 3*x^2
            double coeffs[] = { 1.0, 2.0, 3.0 };
            Polynomial p;
            p.Init(2, coeffs);

            // Для x = 2: 1 + 2*(2) + 3*(4) = 1 + 4 + 12 = 17
            double expected = 17.0;
            double actual = p.evaluate(2.0);

            Assert::AreEqual(expected, actual, 0.0001, L"Помилка при обчисленні evaluate(2.0)");
        }

        // Тест 2: Перевірка операції додавання двох многочленів
        TEST_METHOD(TestAdd)
        {
            // A(x) = 1 + 2*x
            double coeffsA[] = { 1.0, 2.0 };
            Polynomial A;
            A.Init(1, coeffsA);

            // B(x) = 3 + 4*x + 5*x^2
            double coeffsB[] = { 3.0, 4.0, 5.0 };
            Polynomial B;
            B.Init(2, coeffsB);

            // C(x) = A + B = 4 + 6*x + 5*x^2
            Polynomial C = A.add(B);

            Assert::AreEqual(2, C.getDegree(), L"Невірний степінь результату додавання");
            Assert::AreEqual(4.0, C.getCoeff(0), 0.0001, L"Невірний коефіцієнт a0");
            Assert::AreEqual(6.0, C.getCoeff(1), 0.0001, L"Невірний коефіцієнт a1");
            Assert::AreEqual(5.0, C.getCoeff(2), 0.0001, L"Невірний коефіцієнт a2");
        }

        // Тест 3: Перевірка операції множення многочленів
        TEST_METHOD(TestMultiply)
        {
            // A(x) = 1 + 2*x
            double coeffsA[] = { 1.0, 2.0 };
            Polynomial A;
            A.Init(1, coeffsA);

            // B(x) = 3 + 4*x
            double coeffsB[] = { 3.0, 4.0 };
            Polynomial B;
            B.Init(1, coeffsB);

            // C(x) = A * B = (1 + 2*x)*(3 + 4*x) = 3 + 10*x + 8*x^2
            Polynomial C = A.multiply(B);

            Assert::AreEqual(2, C.getDegree(), L"Невірний степінь результату множення");
            Assert::AreEqual(3.0, C.getCoeff(0), 0.0001, L"Невірний коефіцієнт a0 при множенні");
            Assert::AreEqual(10.0, C.getCoeff(1), 0.0001, L"Невірний коефіцієнт a1 при множенні");
            Assert::AreEqual(8.0, C.getCoeff(2), 0.0001, L"Невірний коефіцієнт a2 при множенні");
        }
    };
}