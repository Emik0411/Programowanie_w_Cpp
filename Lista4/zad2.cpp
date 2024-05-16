#include <iostream>
#include <cmath>

using namespace std;


double root(double (*f)(double), double a, double b, double tolerance = 1e-10)
{
    double fa = f(a);
    double fb = f(b);

    if (fa*fb>0)
    {
        cout << "Nie ma pierwiastków" << endl;
        return NAN;
    }

    while((abs(a - b)) > tolerance)
    {
        double c = (a + b) / 2.0;
        double fc = f(c);
        if(fc == 0.0)
        {
            return c;
        }
        else if((fa * fc) < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }


    }
    return (a + b) / 2.0;
}

double e1(double x)
{
    return cos(x) - x;
}

double e2(double x)
{
    return cos(x) - 0.5;
}


int main()
{
    double pierwiastek1 = root(e1, 0, 2, 1e-6);
    cout << "Pierwiastek cos(x)=x: " << pierwiastek1 << endl;
    double pierwiastek2 = root(e2, 0, 1.5, 1e-6);
    cout << "Pierwiastek cos(x)=1/2: " << pierwiastek2 << endl;

    return 0;
}
