#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a = 0.0;
    for(int j=1; j <= 1'000'000; j++)
    {
        a += pow(-1.0, j + 1)/(2.0 * j - 1);
    }
    a *= 4.0;

    double b = 1.0;
    for(int j = 1; j <= 1'000'000; j++)
    {
        b *= (4.0 * j * j)/(4.0 * j * j - 1.0);
    }
    b *= 2.0;

    double c = 0.0;
    for(int j = 1; j <= 1000000; j++)
    {
        c += 1.0/pow(2.0 * j - 1, 2);
    }
    c = sqrt(8.0 * c);

    cout.precision(14);
    cout << "(a) " << a << endl;
    cout << "(b) " << b << endl;
    cout << "(c) " << c << endl;
    cout << "(π) " << M_PI << endl;

    return EXIT_SUCCESS;
}
