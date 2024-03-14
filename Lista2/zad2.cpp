#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N=8;
    int tablica[N]={1,4,7,2,5,9,2,8};

    for(int i=0;i<N;i++)
    {
        cout<<tablica[i]<<", ";
    }


    cout<<endl<<"Posortowane:"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<tablica[i]<<", ";
    }
    return 0;
}
