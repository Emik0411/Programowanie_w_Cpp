#include <iostream>

using namespace std;

void pisz(const int* tab, size_t size, ostream * out)
{
    for(int i = 0; i < size; i++)
    {
        *out << tab[i] << " ";
    }
}

int main()
{
    const int tablica[6] = {1, 2, 3, 4, 5, 6};
    pisz(tablica, 5, &cout);
    return 0;
}
