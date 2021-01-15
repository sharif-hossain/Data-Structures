#include <iostream>

using namespace std;

class node
{
public :
    int info;
    node *link;
};

node *head = NULL;

void insrt(int data)
{
    node *ptr, *tmp;
    ptr = new node();
    ptr -> info = data;
    ptr -> link = NULL;

    if(head == NULL)
    {
        head = ptr;
        tmp = ptr;
    }
    else
    {
        tmp -> link = ptr;
        tmp = ptr;
    }
}

void tvrs()
{
    node *temp;
    temp = head;
    cout << "Printing the elements :" <<endl;
    while(temp != NULL)
    {
        cout << temp -> info << endl;
        temp = temp -> link;
    }
}

void insrt_first(int data)
{
    node *temp;
    temp = new node();
    temp -> info = data;
    temp -> link = head;
    head = temp;
}

void insrt_last(int data)
{
    node *srt;
    node *temp;
    temp = new node();
    temp -> info = data;
    temp -> link = NULL;
    srt = head;
    /* while(1)
     {
         if(srt->link==NULL)
         {
             srt->link = temp;
             break;
         }
         else
         {
             srt= srt->link;
         }
     }  */
    while(srt->link != NULL)
    {
        srt = srt->link;
    }
    srt->link = temp;
}
void insert_after(int pos, int x)
{
    node *temp, *start;
    int i;
    temp = new node();
    temp -> info = x;
    temp -> link = NULL;
    start = head;
    if(pos==0)
    {
        temp->link = start;
        start=temp;
    }
    else
    {
        for(i=1, start=head; i<pos; i++)
        {
            start=start->link;
        }
        temp->link=start->link;
        start->link=temp;
    }
}

int main()
{
    int n,item, pos,x;
    cout << "Enter the item size :" << endl;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> item;
        insrt(item);
    }
    cout << "Enter item to add first" << endl;
    cin >> item;
    insrt_first(item);
    tvrs();

    cout << "Enter item to add last " << endl;
    cin >> item;
    insrt_last(item);
    tvrs();

    cout << "Enter insert after position : " << endl;
    cin >> pos;
    cout << "enter data : " << endl;
    cin >> x;
    insert_after(pos, x);
    tvrs();

    return 0;
}


