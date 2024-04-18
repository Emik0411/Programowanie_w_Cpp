#include <iostream>

using namespace std;

int suma(const int tab[], unsigned size)
{
    int a = 0;
    for(int i = 0; i < size; i++)
    {
        a += tab[i];
    }
    return a;
}

int main()
{
   const int tablica[6] = {1, 2, 3, 4, 5, 6};
   cout << suma(tablica, 4) << endl;
   return 0;
}
