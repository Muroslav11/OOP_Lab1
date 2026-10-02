#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.1/Line.h"
#include "../OOP_Lab_1.1/Line.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLine
{
    TEST_CLASS(UnitTestLine)
    {
    public:
        // Тест перевірки коректного встановлення коефіцієнта A (A != 0)
        TEST_METHOD(TestSetFirst_Valid)
        {
            Line line;
            bool result = line.SetFirst(3.5);

            Assert::IsTrue(result);
            Assert::AreEqual(3.5, line.GetFirst());
        }

        // Тест блокування нульового коефіцієнта A
        TEST_METHOD(TestSetFirst_ZeroInvalid)
        {
            Line line;
            bool result = line.SetFirst(0.0);

            Assert::IsFalse(result);
            // За логікою методу значення встановлюється у 1, щоб запобігти помилці
            Assert::AreEqual(1.0, line.GetFirst());
        }

        // Тест методу Init() з валідними параметрами
        TEST_METHOD(TestInit_Valid)
        {
            Line line;
            bool result = line.Init(2.0, -4.0);

            Assert::IsTrue(result);
            Assert::AreEqual(2.0, line.GetFirst());
            Assert::AreEqual(-4.0, line.GetSecond());
        }

        // Тест методу Init() з нульовим першим коефіцієнтом
        TEST_METHOD(TestInit_InvalidFirst)
        {
            Line line;
            bool result = line.Init(0.0, 5.0);

            Assert::IsFalse(result);
        }

        // Тест обчислення функції y = Ax + B
        TEST_METHOD(TestFunction_Calculation)
        {
            Line line;
            line.Init(2.0, 3.0); // y = 2x + 3

            double x = 4.0;
            double expected_y = 11.0; // 2 * 4 + 3 = 11
            double actual_y = line.function(x);

            Assert::AreEqual(expected_y, actual_y, 0.0001);
        }

        // Тест обчислення функції з від'ємними значеннями
        TEST_METHOD(TestFunction_NegativeValues)
        {
            Line line;
            line.Init(-3.0, 5.0); // y = -3x + 5

            double x = 2.0;
            double expected_y = -1.0; // -3 * 2 + 5 = -1
            double actual_y = line.function(x);

            Assert::AreEqual(expected_y, actual_y, 0.0001);
        }
    };
}