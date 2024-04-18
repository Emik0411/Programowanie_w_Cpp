#include <iostream>

using namespace std;

void iota(int tab[], unsigned size)
{
    for(int i = 0; i < size; i++)
    {
        tab[i]=i;
    }
}

int main()
{
    int N = 9;
    int tablica[N] = {};
   iota(tablica, N);

   for(int i = 0; i < N; i++)
   {
       cout << tablica[i] << " ";
   }
   return 0;
}
