#include <iostream>

using namespace std;

double down(double N)
{
    double a=0.0;
    for(int i=1;i<=N;i++)
    {
        a=a+1.0/i;
    }
    return a;
}

double up(double N)
{
    double a=0.0;
    for(int i=N;i>=1;i--)
    {
        a=a+1.0/i;
    }
    return a;
}

double roznica(double N)
{
    return up(N)-down(N);
}



float downf(float N)
{
    float a=0;
    for(int i=1;i<=N;i++)
    {
        a=a+1.0/i;
    }
    return a;
}

float upf(float N)
{
    float a=0;
    for(int i=N;i>=1;i--)
    {
        a=a+1.0/i;
    }
    return a;
}

float roznicaf(float N)
{
    return upf(N)-downf(N);
}

int main()
{
    cout<<"(a)"<<endl;
    cout<<"N=100 :  "<<roznica(100)<<endl;
    cout<<"N=100000 :  "<<roznica(100000)<<endl;
    cout<<"N=100000000 :  "<<roznica(100000000)<<endl;

    cout<<endl<<"(b)"<<endl;
    cout<<"N=100 :  "<<roznicaf(100)<<endl;
    cout<<"N=100000 :  "<<roznicaf(100000)<<endl;
    cout<<"N=100000000 :  "<<roznicaf(100000000)<<endl;

    return 0;
}
