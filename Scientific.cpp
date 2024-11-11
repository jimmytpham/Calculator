#include "Scientific.h"
#include <cmath>

/* Jimmy Pham
*  T00629354
*  COMP 3141
*  Final Project
*/

double Scientific::sin(double n)
{
	return System::Math::Sin(n);
}

double Scientific::cos(double n)
{
	return System::Math::Cos(n);;
}

double Scientific::tan(double n)
{
	return System::Math::Tan(n);
}

double Scientific::log(double n)
{
	return System::Math::Log10(n);
}

double Scientific::ln(double n)
{
	return System::Math::Log(n);
}

double Scientific::factorial(double n)
{
    if (n < 0)
    {
        // For negative integer
        return System::Double::NaN;
    }

    if (n == 0 || n == 1)
    {
        // Factorial of 0 and 1 is 1
        return 1.0;
    }

    double result = 1.0;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

double Scientific::cubed(double n)
{
    return n * n * n;
}

double Scientific::power(double base, double exponent)
{
    return System::Math::Pow(base, exponent);
}
