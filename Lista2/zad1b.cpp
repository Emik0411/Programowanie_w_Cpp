#include <iostream>

using namespace std;

void suma(const int tab[], unsigned size, int* result)
{
    *result = 0;
    for(int i = 0; i < size; i++)
    {
        *result += tab[i];
    }
}

int main()
{
    const int tablica[6] = {1, 2, 3, 4, 5, 6};
    int wynik;
    suma(tablica, 4, &wynik);
    cout << wynik << endl;
    return 0;
}
