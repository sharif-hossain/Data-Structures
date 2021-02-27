#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;

void Insert(int x, int n)
{
    Node* temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;

    if(n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 1; i < n-1; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Reverse()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void Print()
{
    Node* temp = head;
    while(temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    int n;

    Insert(4,1);
    Insert(5,1);
    Insert(7,2);
    Insert(9,3);
    Insert(1,1);
    Insert(3,2);
    Print();
    cout << endl;

    Reverse();
    Print();
    return 0;
}
