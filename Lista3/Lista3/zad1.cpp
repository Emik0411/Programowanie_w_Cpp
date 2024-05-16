#include <iostream>

using namespace std;

struct Link
{
    int value;
    Link* next = nullptr;
};

size_t size(const Link* head)
{
    size_t liczba = 0;
    const Link* current = head;
    while (current != nullptr)
    {
        liczba += 1;
        current = current -> next;
    }
    return liczba;
}

size_t sum(const Link* head)
{
    size_t suma = 0;
    const Link* current = head;
    while (current != nullptr)
    {
        suma += current -> value;
        current = current -> next;
    }
    return suma;
}

int main()
{
    Link* head = new Link;
    head -> value = 1;

    Link* a1 = new Link;
    a1 -> value = 3;
    head -> next = a1;

    Link* a2 = new Link;
    a2 -> value = 6;
    a1 -> next = a2;

    Link* a3 = new Link;
    a3 -> value = 9;
    a2 -> next = a3;

    cout << "Liczba elementów: " << size(head) << endl;
    cout << "Suma: " << sum(head) << endl;

    return 0;
}
