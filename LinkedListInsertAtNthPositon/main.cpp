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

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Insert(7,5);
    Print();
    return 0;
}
