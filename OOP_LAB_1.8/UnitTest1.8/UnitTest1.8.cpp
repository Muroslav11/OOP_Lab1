#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_1.8/Payment.h"  
#include "../OOP_Lab_1.8/Payment.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace PaymentUnitTest
{
    TEST_CLASS(PaymentCalculationTests)
    {
    public:

        // Тест розрахунку нарахованої суми
        TEST_METHOD(TestCalculateAccruedSum)
        {
            // Оклад 20000 грн 00 коп, надбавка 10%, відпрацьовано 20 робочих днів з 20
            Payment p;
            p.Init("Шевченко", "Тарас", "Григорович", 20000, 0, 2018, 10.0, 20, 20);

            // Нараховано = (20000 / 20 * 20) * (1 + 10/100) = 22000,00 грн
            string accruedStr = p.getAccruedSumString();
            Assert::AreEqual(string("22000,00"), accruedStr);
        }

        // Тест розрахунку чистої виплати на руки
        TEST_METHOD(TestCalculateNetPay)
        {
            // Оклад 10000 грн 00 коп, надбавка 0%, 20 з 20 днів
            Payment p;
            p.Init("Іваненко", "Іван", "Іванович", 10000, 0, 2020, 0.0, 20, 20);

            // Нараховано = 10000,00 грн
            // Утримано: ПФ (1%) = 100 грн, Податок (13%) = 1300 грн. Разом утримано = 1400 грн
            // На руки = 10000 - 1400 = 8600,00 грн
            string netPayStr = p.calculateNetPayString();
            Assert::AreEqual(string("8600,00"), netPayStr);
        }

        // Тест обчислення стажу роботи
        TEST_METHOD(TestCalculateExperience)
        {
            Payment p;
            p.Init("Петренко", "Петро", "Петрович", 15000, 0, 2016, 5.0, 22, 22);

            // Стаж для 2026 року: 2026 - 2016 = 10 років
            int exp = p.calculateExperience(2026);
            Assert::AreEqual(10, exp);
        }

        // Тест валідації робочих днів у сетерах
        TEST_METHOD(TestSetWorkingDaysValidation)
        {
            Payment p;
            p.Init("Коваль", "Олег", "Петрович", 12000, 0, 2021, 0.0, 20, 20);

            // Намагаємося встановити некоректну кількість робочих днів (>31 або <1)
            bool resultInvalidHigh = p.setWorkingDays(35);
            Assert::IsFalse(resultInvalidHigh);

            bool resultInvalidLow = p.setWorkingDays(0);
            Assert::IsFalse(resultInvalidLow);

            // Корректне значення
            bool resultValid = p.setWorkingDays(22);
            Assert::IsTrue(resultValid);
        }
    };
}