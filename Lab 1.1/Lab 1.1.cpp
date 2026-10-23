// Lab 1.1.cpp 
// головний файл проекту – функція main
#include "FloatRange.h"
#include <iostream>

using namespace std;

FloatRange makeFloatRange(double f, double s)
{
    FloatRange r;
    if (!r.Init(f, s))
        cout << "Wrong arguments to Init! (first must be less than second)" << endl;
    return r;
}

int main()
{
    // 1. Тестування стандартної ініціалізації та перевірки діапазону
    FloatRange r1;
    r1.Init(2.5, 10.0);
    r1.Display();

    double testVal = 5.0;
    cout << "Checking value " << testVal << ": "
        << (r1.rangeCheck(testVal) ? "Inside range" : "Outside range") << endl;

    // 2. Введення з клавіатури за допомогою методу Read()
    FloatRange r2;
    r2.Read();
    r2.Display();

    cout << "Enter a value to check for r2: ";
    double val;
    cin >> val;
    cout << "Checking value " << val << ": "
        << (r2.rangeCheck(val) ? "Inside range" : "Outside range") << endl;

    // 3. Використання зовнішньої функції makeFloatRange()
    double f, s;
    cout << endl << "Input range for makeFloatRange:" << endl;
    cout << "  first = "; cin >> f;
    cout << "  second = "; cin >> s;

    FloatRange r3 = makeFloatRange(f, s);
    r3.Display();

    return 0;
}