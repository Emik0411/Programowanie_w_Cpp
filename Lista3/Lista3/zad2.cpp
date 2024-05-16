#include <iostream>

using namespace std;

struct Link
{
    int value;
    Link* next = nullptr;
};

void release(Link** phead)
{
    if (*phead == nullptr)
    {
        return;
    }
    Link* tmp = *phead;
    *phead = (*phead)->next;
    delete tmp;
    release(phead);
}

void Pokaz_liste(Link* head)
{
    Link* current = head;
    while (current != nullptr)
    {
        cout << current -> value << " ";
        current = current -> next;
    }
    cout << endl;
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

    Pokaz_liste(head);

    release(&head);

    Pokaz_liste(head);


    return 0;
}
