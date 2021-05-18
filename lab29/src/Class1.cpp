#include "Class1.h"

Class1::Class1()
{
    b=0;
}

Class1::Class1(double a, int b)
{
    SetValue(a);
    this->b = b;
}

double Class1::GetValue()
{
    return Class::GetValue() + double(b);
}