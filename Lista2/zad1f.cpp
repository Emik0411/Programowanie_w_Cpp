#include <iostream>

using namespace std;

int dot_product(const int* tab1, const int* tab2, size_t size)
{
    int iloczyn = 0;
    for(int i = 0; i < size; i++)
    {
        iloczyn += (tab1[i] * tab2[i]);
    }
    return iloczyn;
}

int main()
{
    size_t n = 4;
    const int tab1[n] = {2, 2, 3, 4};
    const int tab2[n] = {7, 6, 5, 4};

    cout << dot_product(tab1, tab2, n) << endl;
    return 0;
}
