#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
};

node* head;
/*
void insertFromBeginning(int x)
{
    node* temp ;
    temp = new node();
    temp -> data = x;
   // temp -> next = NULL;

   // if(head != NULL)
   // {
        temp->next = head;
        head = temp;
  //  }
}
*/
void insertAtEnd(int x)
{
    node *temp, *start;
    temp = new node();
    temp -> data = x;
    temp -> next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else{
        start -> next = temp;
    }
    start = temp;
    /*
    start = head;
    while(start -> next != NULL)
        {
            start = start -> next;
        }
        start -> next = temp;  */
}
void Delete(int x)
{
    node* temp1 = head;

    if(x == 1)
    {
        head = temp1 -> next;
        delete(temp1);
        return;
    }

    else{
        for(int i = 1; i < x - 1; i++)
        {
            temp1 = temp1 -> next;
        }

        node* temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete(temp2);
    }
}
void Print()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    int n, item, pos;
    head = NULL;
    cout << "How many data you want to insert : " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> item;
        //insertFromBeginning();
        insertAtEnd(item);

    }
    cout << "current list : " ;
    Print();
  /* cout << "\nChose from below : " << endl;
    while(1)
    {
        int n;
        cout << "\n1 for delete first\n2 for delete last\n3 for delete after a node\n4 for delete before a node\n" << endl;
        cin >> n;
    }  */

    cout << "\nenter position to be deleted : " ;
    cin >> pos;
    Delete(pos);
    cout << "Existing elements in list:" << endl;
    Print();
    return 0;
}
