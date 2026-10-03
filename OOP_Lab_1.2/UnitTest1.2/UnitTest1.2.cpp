#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.2/Matrix.h"
#include "../OOP_Lab_1.2/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix
{
    TEST_CLASS(UnitTestMatrix)
    {
    public:
        // 1. Тест успішної ініціалізації валідними розмірностями
        TEST_METHOD(TestInit_ValidDimensions)
        {
            Matrix m;
            bool result = m.Init(3, 4);

            Assert::IsTrue(result);
            Assert::AreEqual(3, m.getRows());
            Assert::AreEqual(4, m.getCols());
            Assert::AreEqual(0, m.getState());
        }

        // 2. Тест блокування некоректних розмірностей (<= 0)
        TEST_METHOD(TestInit_InvalidDimensions)
        {
            Matrix m;
            bool result = m.Init(0, -5);

            Assert::IsFalse(result);
            // Код помилки 3 – невідповідність розмірностей
            Assert::AreEqual(3, m.getState());
        }

        // 3. Тест коректного запису та зчитування елемента
        TEST_METHOD(TestGetElement_Valid)
        {
            Matrix m;
            m.Init(2, 2);

            // Оскільки в Init масив заповнюється нулями
            Assert::AreEqual(0, m.getElement(0, 0));
            Assert::AreEqual(0, m.getState());
        }

        // 4. Тест виходу за межі діапазону (фіксація state = 2)
        TEST_METHOD(TestGetElement_OutOfBounds)
        {
            Matrix m;
            m.Init(2, 2);

            // Звернення до неіснуючого індексу
            int val = m.getElement(5, 5);

            Assert::AreEqual(0, val);
            Assert::AreEqual(2, m.getState()); // state 2 = помилка меж
        }

        // 5. Тест операції множення матриці на число
        TEST_METHOD(TestMultiply_Scalar)
        {
            Matrix m;
            m.Init(2, 2);

            // Безпосереднє заповнення елементів для тесту
            int** data = m.getData();
            data[0][0] = 1;
            data[0][1] = 2;
            data[1][0] = 3;
            data[1][1] = 4;

            m.Multiply(3);

            Assert::AreEqual(3, m.getElement(0, 0));
            Assert::AreEqual(6, m.getElement(0, 1));
            Assert::AreEqual(9, m.getElement(1, 0));
            Assert::AreEqual(12, m.getElement(1, 1));
        }

        // 6. Тест очищення пам'яті при повторному Init
        TEST_METHOD(TestInit_Reinitialization)
        {
            Matrix m;
            m.Init(2, 2);
            bool reInitResult = m.Init(4, 5);

            Assert::IsTrue(reInitResult);
            Assert::AreEqual(4, m.getRows());
            Assert::AreEqual(5, m.getCols());
        }
    };
}