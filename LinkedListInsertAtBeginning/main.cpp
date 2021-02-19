#include <iostream>

using namespace std;

struct node
{

    int data;
    node* next;
};
//node* head = NULL;

void Insert(node** head, int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = *head;
    *head = temp;
    //return head;
}

void Print(node* head)
{
    // node* temp = head;
    cout << "List is : ";
    while(head!= NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node* head = NULL;
    int n, x;
    cout << "Enter no of element : ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter elements: ";
        cin >> x;
        Insert(&head, x);
        Print(head);
    }
    return 0;
}
