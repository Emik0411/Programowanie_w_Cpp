#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double t0=1.0/sqrt(3);
    long double ti=0.0;

    cout<<"(a)"<<endl;

    long double a=0.0;
    for(int i=0;i<=30;i++)
    {
        if(i==0)
        {
           ti=t0;
        }
        else
        {
            ti=1.0*(sqrt(ti*ti+1)-1)/ti;
        }

        a=6.0*pow(2,i)*ti;

        cout<<"i="<<i<<" π="<<a<<endl;
    }

    cout<<endl<<"(b)"<<endl;

    long double b=0.0;
    for(int i=0;i<=30;i++)
    {
        if(i==0)
        {
           ti=t0;
        }
        else
        {
            ti=1.0*ti/(sqrt(ti*ti+1)+1);
        }

        a=6.0*pow(2,i)*ti;

        cout<<"i="<<i<<" π="<<a<<endl;
    }

    return 0;
}
