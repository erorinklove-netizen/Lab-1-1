#include "pch.h"
#include "CppUnitTest.h"
#include "D:\education\ООП\Lab 1.1\FloatRange.h" // Шлях до заголовного файлу вашого основного проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Тест 1: Перевірка коректної ініціалізації та гетерів
        TEST_METHOD(TestInitAndGetters)
        {
            FloatRange r;
            bool res = r.Init(2.0, 8.5);
            Assert::IsTrue(res);
            Assert::AreEqual(2.0, r.GetFirst());
            Assert::AreEqual(8.5, r.GetSecond());
        }

        // Тест 2: Перевірка некоректної ініціалізації (first >= second)
        TEST_METHOD(TestInvalidInit)
        {
            FloatRange r;
            bool res = r.Init(10.0, 5.0);
            Assert::IsFalse(res);
        }

        // Тест 3: Перевірка методу rangeCheck()
        TEST_METHOD(TestRangeCheck)
        {
            FloatRange r;
            r.Init(1.0, 10.0);

            Assert::IsTrue(r.rangeCheck(5.0));   // Всередині
            Assert::IsTrue(r.rangeCheck(1.0));   // На лівій границі
            Assert::IsTrue(r.rangeCheck(10.0));  // На правій границі
            Assert::IsFalse(r.rangeCheck(0.9));  // Зліва за межами
            Assert::IsFalse(r.rangeCheck(10.1)); // Справа за межами
        }

        // Тест 4: Перевірка сеттерів SetFirst та SetSecond
        TEST_METHOD(TestSetters)
        {
            FloatRange r;
            r.Init(0.0, 10.0);

            Assert::IsTrue(r.SetFirst(3.0));     // 3.0 < 10.0 (успішно)
            Assert::IsFalse(r.SetFirst(15.0));   // 15.0 не менше 10.0 (помилка)

            Assert::IsTrue(r.SetSecond(20.0));   // 20.0 > 3.0 (успішно)
            Assert::IsFalse(r.SetSecond(1.0));   // 1.0 не більше 3.0 (помилка)
        }
    };
}