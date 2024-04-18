#include <iostream>
#include <cstdlib>

using namespace std;

int sortuj(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if(arg1 % 2 == 0 && arg2 % 2 == 0)
    {
        return arg1 - arg2;
    }
    if(arg1 % 2 == 1 && arg2 % 2 == 1)
    {
        return arg2 - arg1;
    }

    if(arg1 % 2 == 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    const int rozmiar = 8;
    int tablica[rozmiar] = {1, 4, 7, 2, 5, 9, 2, 8};

    qsort(tablica, rozmiar, sizeof(int), sortuj);

    for(int i = 0; i < rozmiar; i++)
    {
        cout << tablica[i] << " ";
    }
}
