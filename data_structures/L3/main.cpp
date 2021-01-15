#include <iostream>

using namespace std;

class node
{
public :
    int data;
    node *next;
};

node *head = NULL;
node *temp;

void insert(int x)
{
    node *ptr;
    ptr = new node();
    ptr -> data = x;
    ptr -> next = NULL;

    if(head == NULL)
    {
        head = ptr;
        temp = ptr;
    }
    else
    {
        temp -> next = ptr;
        temp = ptr;
    }
}

void traverse()
{
    node *srt;
    srt = head;
    cout << "Printing the elements :" <<endl;
    while(srt!=NULL)
    {
        cout << srt -> data << endl;
        srt = srt -> next;
    }
}

void insert_first(int x)
{
    node *ptr;
    ptr = new node();
    ptr -> data = x;
    ptr -> next = head;
    head = ptr;
}

void insert_last(int x)
{
    node *srt;
    node *ptr;
    ptr = new node();
    ptr -> data = x;
    ptr -> next = NULL;
    srt = head;
    while(1)
    {
        if(srt-> next == NULL)
        {
            srt->next = ptr;
            break;
        }
        else
            srt= srt->next;

    }
}

int main()
{
    int n,item;
    cout << "Enter the item size :" << endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> item;
        insert(item);
    }
    cout << "Enter item to add first" << endl;
    cin >> item;
    insert_first(item);
    traverse();

    cout << "Enter item to add last " << endl;
    cin >> item;
    insert_last(item);
    traverse();

    return 0;
}

