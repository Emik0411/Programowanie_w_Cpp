#include <iostream>
#include <vector>

using namespace std;

double operator*(const vector<double> & v, const vector<double> & w)
{
    double liczba = 0;
    for(int i = 0; i < sizeof(v); i++)
    {
        liczba += v[i] * w[i];
    }
    return liczba;
}

int main()
{
    vector<double> v = {1, 2, 3, 4};
    vector<double> w = {5, 6, 7, 8};

    cout << v * w << endl;

    return 0;
}
