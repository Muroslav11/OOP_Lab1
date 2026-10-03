#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.3/LongLong.h"
#include "../OOP_Lab_1.3/LongLong.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLongLong
{
    TEST_CLASS(UnitTestLongLong)
    {
    public:
        // 1. Тест инициализации и геттеров
        TEST_METHOD(TestInitAndGetters)
        {
            LongLong obj;
            bool result = obj.Init(5, 100);

            Assert::IsTrue(result);
            Assert::AreEqual(5L, obj.GetHigh());
            Assert::AreEqual(100L, obj.GetLow());
        }

        // 2. Тест преобразования в 64-битное число ToInt64()
        TEST_METHOD(TestToInt64)
        {
            LongLong obj;
            obj.Init(1, 0); // 1 * 2^32 = 4294967296

            long long expected = 4294967296LL;
            Assert::AreEqual(expected, obj.ToInt64());
        }

        // 3. Тест дружественной функции сложения Add()
        TEST_METHOD(TestAdd)
        {
            LongLong a, b;
            a.Init(0, 150);
            b.Init(0, 250);

            LongLong sum = Add(a, b);

            Assert::AreEqual(0L, sum.GetHigh());
            Assert::AreEqual(400L, sum.GetLow());
            Assert::AreEqual(400LL, sum.ToInt64());
        }

        // 4. Тест дружественной функции умножения Multiply()
        TEST_METHOD(TestMultiply)
        {
            LongLong a, b;
            a.Init(0, 20);
            b.Init(0, 30);

            LongLong prod = Multiply(a, b);

            Assert::AreEqual(0L, prod.GetHigh());
            Assert::AreEqual(600L, prod.GetLow());
            Assert::AreEqual(600LL, prod.ToInt64());
        }

        // 5. Тест переноса битов при сложении в старшую часть
        TEST_METHOD(TestAddWithCarry)
        {
            LongLong a, b;
            a.Init(0, 4294967295L); // 0xFFFFFFFF (максимальное беззнаковое 32-битное число)
            b.Init(0, 1L);

            LongLong sum = Add(a, b);

            // Переполнение младших 32 бит должно перейти в High = 1, Low = 0
            Assert::AreEqual(1L, sum.GetHigh());
            Assert::AreEqual(0L, sum.GetLow());
            Assert::AreEqual(4294967296LL, sum.ToInt64());
        }

        // 6. Тест дружественных функций сравнения (Less, NotLess, Greater)
        TEST_METHOD(TestComparisons)
        {
            LongLong smallObj, bigObj;
            smallObj.Init(0, 100);
            bigObj.Init(1, 10);

            Assert::IsTrue(Less(smallObj, bigObj));
            Assert::IsFalse(Greater(smallObj, bigObj));
            Assert::IsFalse(NotLess(smallObj, bigObj));
            Assert::IsTrue(NotLess(bigObj, smallObj));
        }
    };
}