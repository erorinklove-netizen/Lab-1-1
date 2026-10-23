//////////////////////////////////////////////////////////////////////////////
// FloatRange.h 
// заголовний файл – визначення класу
#pragma once
#include <iostream>

using namespace std;

class FloatRange
{
private:
    double first;   // ліва границя діапазону
    double second;  // права границя діапазону
public:
    double GetFirst() const { return first; }
    double GetSecond() const { return second; }

    bool SetFirst(double value);
    bool SetSecond(double value);

    bool Init(double f, double s);
    void Read();
    void Display() const;

    bool rangeCheck(double val) const;
};
