#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.7/Payment.h"  
#include "../OOP_Lab_1.7/Payment.cpp"
#include "../OOP_Lab_1.7/Money.h"  
#include "../OOP_Lab_1.7/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PaymentUnitTest
{
    TEST_CLASS(MoneyTests)
    {
    public:

        TEST_METHOD(TestMoneyAddition)
        {
            Money m1(100, 50);
            Money m2(50, 75);
            Money result = m1.add(m2);

            // 100 грн 50 коп + 50 грн 75 коп = 151 грн 25 коп
            Assert::AreEqual(151L, result.getHryvnias());
            Assert::AreEqual((unsigned char)25, result.getKopecks());
        }

        TEST_METHOD(TestMoneySubtraction)
        {
            Money m1(200, 20);
            Money m2(50, 50);
            Money result = m1.sub(m2);

            // 200 грн 20 коп - 50 грн 50 коп = 149 грн 70 коп
            Assert::AreEqual(149L, result.getHryvnias());
            Assert::AreEqual((unsigned char)70, result.getKopecks());
        }

        TEST_METHOD(TestMoneyDivSums)
        {
            Money m1(150, 0);
            Money m2(50, 0);
            double ratio = m1.divSums(m2);

            // 150 / 50 = 3.0
            Assert::AreEqual(3.0, ratio, 0.0001);
        }
    };

    TEST_CLASS(PaymentCalculationTests)
    {
    public:

        TEST_METHOD(TestCalculateAccruedSum)
        {
            // Оклад 20000 грн 00 коп, прийом 2018 р., надбавка 10%, відпрацьовано 20 робочих днів з 20
            Money rate(20000, 0);
            Payment p;
            p.Init("Шевченко", "Тарас", "Григорович", rate, 2018, 10.0, 20, 20);

            // Нараховано = (20000 / 20 * 20) * 1.10 = 22000 грн 00 коп
            Money accrued = p.calculateAccruedSum();
            Assert::AreEqual(22000L, accrued.getHryvnias());
            Assert::AreEqual((unsigned char)0, accrued.getKopecks());
        }

        TEST_METHOD(TestCalculateNetPay)
        {
            // Оклад 10000 грн 00 коп, надбавка 0%, 20 з 20 днів
            Money rate(10000, 0);
            Payment p;
            p.Init("Іваненко", "Іван", "Іванович", rate, 2020, 0.0, 20, 20);

            // Нараховано = 10000 грн
            // ПФ (1%) = 100 грн, Податок (13%) = 1300 грн. Утримано = 1400 грн
            // На руки = 10000 - 1400 = 8600 грн 00 коп
            Money netPay = p.calculateNetPay();
            Assert::AreEqual(8600L, netPay.getHryvnias());
            Assert::AreEqual((unsigned char)0, netPay.getKopecks());
        }

        TEST_METHOD(TestCalculateExperience)
        {
            Money rate(15000, 0);
            Payment p;
            p.Init("Петренко", "Петро", "Петрович", rate, 2016, 5.0, 22, 22);

            // Стаж для 2026 року: 2026 - 2016 = 10 років
            int exp = p.calculateExperience(2026);
            Assert::AreEqual(10, exp);
        }
    };
}