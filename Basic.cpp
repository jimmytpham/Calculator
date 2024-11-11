#include "Basic.h"
#include <cmath>

/* Jimmy Pham
*  T00629354
*  COMP 3141
*  Final Project
*/

Basic::Basic()
{
}

double Basic::add(double a, double b)
{
    return a + b;
}

double Basic::subtract(double a, double b)
{
    return a - b;
}

double Basic::multiply(double a, double b)
{
    return a * b;
}

double Basic::divide(double a, double b)
{
    // Divide by zero
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        return 0; 
    }
}

double Basic::squareRoot(double a)
{
    //Negative number
    if (a >= 0)
    {
        return std::sqrt(a);
    }
    else
    { 
        return 0;
    }
}

double Basic::squared(double a)
{
    return a * a;
}