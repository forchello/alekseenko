#include "Class.h"

class Class1: public Class
{
    int b;

    public:
    
    Class1();
    Class1(double a, int b);

    double GetValue() override;
};