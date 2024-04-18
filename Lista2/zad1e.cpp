#include <iostream>

using namespace std;

void reverse(int* tab, size_t size)
{
    int re[size] = {};
    for(int i = 0; i < size; i++)
    {
        re[size-i-1] = tab[i];
    }
    for(int i = 0; i < size; i++)
    {
        tab[i] = re[i];
    }
}

int main()
{
   int tablica[6] = {1, 2, 3, 4, 5, 6};
   reverse(tablica, 4);
   for(int i = 0; i < 6; i++)
      {
          cout << tablica[i] << " ";
      }
   return 0;
}
