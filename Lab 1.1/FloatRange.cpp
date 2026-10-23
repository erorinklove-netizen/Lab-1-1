//////////////////////////////////////////////////////////////////////////////
// FloatRange.cpp 
// файл реалізації – реалізація методів класу
#include "FloatRange.h"
#include <iostream>

using namespace std;

bool FloatRange::SetFirst(double value)
{
    if (value < second)
    {
        first = value;
        return true;
    }
    return false;
}

bool FloatRange::SetSecond(double value)
{
    if (first < value)
    {
        second = value;
        return true;
    }
    return false;
}

bool FloatRange::Init(double f, double s)
{
    if (f < s)
    {
        first = f;
        second = s;
        return true;
    }
    first = 0.0;
    second = 1.0;
    return false;
}

void FloatRange::Read()
{
    double f, s;
    do
    {
        cout << "Input range values (first < second):" << endl;
        cout << "  first = "; cin >> f;
        cout << "  second = "; cin >> s;
    } while (!Init(f, s));
}

void FloatRange::Display() const
{
    cout << endl;
    cout << "  first (left boundary) = " << first << endl;
    cout << "  second (right boundary) = " << second << endl;
}

bool FloatRange::rangeCheck(double val) const
{
    return (val >= first && val <= second);
}