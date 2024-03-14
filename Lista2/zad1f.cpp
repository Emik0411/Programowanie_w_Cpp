#include <iostream>

using namespace std;

int dot_product(const int* tab1,const int* tab2,size_t size)
{
    int iloczyn=0;
    for(int i=0;i<size;i++)
    {
        iloczyn=iloczyn+(tab1[i]*tab2[i]);
    }
    return iloczyn;
}

int main()
{
    const int tab1[7]={1,2,3,4,5,6,7};
    const int tab2[7]={7,6,5,4,3,2,1};
    size_t n=4;
    cout<<dot_product(tab1,tab2,n)<<endl;
    return 0;
}
