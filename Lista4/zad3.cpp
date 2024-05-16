#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc<2 || (string(argv[1]) == "-help") || (string(argv[1]) == "-h") )
    {
        cout << "Program pomaga wygrać w grę nim." << endl;
        cout << "\tskładnia:" << endl;
        cout << "\tnim liczba_1 liczba_2 ..." << endl;
        cout << "\tgdzie liczba_1,... to liczby kamieni w kolejnych rzędach" << endl;
        return 0;
    }

    vector<int> piles;
        for (int i = 1; i < argc; ++i)
        {
            piles.push_back(atoi(argv[i]));
        }

        int Sum = 0;
        for (int pile : piles)
        {
            Sum ^= pile;
        }

        if (Sum == 0)
        {
           cout << "rób co chcesz, strategia wygrywająca nie istnieje" << endl;
           return 0;
        }

        for (size_t i = 0; i < piles.size(); ++i)
        {
            int stonesToRemove = piles[i] ^ Sum;

            if (stonesToRemove < piles[i])
            {
                cout << "z rzędu nr " << i+1 << " zabierz " << piles[i] - stonesToRemove << " kamienie" << endl;
            }

        }


    return 0;
}
