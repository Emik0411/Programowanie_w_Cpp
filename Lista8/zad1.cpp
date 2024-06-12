#include <iostream>
#include <vector>
#include <complex>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& wektor)
{
    out << "[";
    for(int i = 0; i < wektor.size() - 1; i++)
    {
        out << wektor[i] << ", ";
    }
    out << wektor[wektor.size() - 1] << "]";
    return out;
}

int main()
{
    std::vector<int> Wektor_int = {5, 3, 7, 3};
    std::vector<double> Wektor_double = {5.6, 3.4, 7.5, 3.1};
    std::vector<std::complex<double>> Wektor_complex = {{2.5, 2.9}, {2.7, 4.1}, {91.5, 46.2}};
    std::cout << Wektor_int << std::endl;
    std::cout << Wektor_double << std::endl;
    std::cout << Wektor_complex << std::endl;
    return 0;
}
