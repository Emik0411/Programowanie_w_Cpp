#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a=0.0;
    for(int j=1;j<=1000000;j++)
    {
        a=a+1.0*((pow((-1),(j+1)))/(2*j-1));
    }
    a=a*4;

    double b=1.0;
    for(int j=1;j<=1000000;j++)
    {
        b=b*((4.0*j*j)/(4.0*j*j-1.0));
    }
    b=b*2.0;

    double c=0.0;
    for(int j=1;j<=1000000;j++)
    {
        c=c+1.0*(1/(pow((2*j-1),2)));
    }
    c=pow(c*8,0.5);

    cout<<"(a) "<<a<<endl;
    cout<<"(b) "<<b<<endl;
    cout<<"(c) "<<c<<endl;
    cout<<"(π) "<<M_PI<<endl;

    return 0;
}
