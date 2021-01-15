#include <iostream>

using namespace std;

class node
{
public:
    int info;
    node *link;
};
node *head = NULL,*tmp,*last = NULL;

void insert(int data)
{
    node *ptr=new node();
    ptr -> info= data;
    ptr -> link = head;
    last = ptr;
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
void insert_first(int data)
{
    node *ptr = new node();
    ptr -> info = data;
    ptr -> link = head;
    head = ptr;
    last -> link = head;
}
void insert_last(int data)
{
    node *ptr = new node();
    ptr -> info = data;
    ptr -> link = head;
    last -> link = ptr;
    last = ptr;
}
void insert_after(int data,int element)
{
    node *srt,*ptr = new node();
    ptr -> info = data;
    srt = head;
    if(element==last->info)
    {
        insert_last(data);
    }
    else
    {
        while(1)
        {
            if(srt->info == element)
            {
                ptr -> link = srt -> link;
                srt -> link = ptr;
                break;
            }
            else
            {
                srt = srt -> link;
            }
        }
    }
}
void insert_before (int data,int element)
{
    node *tmp,*srt,*ptr = new node ();
    ptr -> info = data;
    srt = head;
    if(element==srt -> info)
    {
        insert_first(data);
    }
    else
    {
        while(1)
        {
            if(srt -> info == element)
            {
                ptr -> link = srt;
                tmp -> link = ptr;
                break;
            }
            else
            {
                tmp = srt;
                srt = srt -> link;
            }
        }
    }
}
void travers()
{
    node *srt;
    srt = head;
    while(1)
    {
        if(srt -> link != head)
        {
            cout << srt -> info << endl;
            srt = srt -> link;
        }
        else
        {
            cout << srt -> info << endl;
            break;
        }
    }
}
int main()
{
    int n,item,c;
    cout << "Enter the elements numbers :" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> item;
        insert(item);
    }
    while(1)
    {
        cout <<"1 for insert first\n2 for insert last\n3 for insert after\n4 for insert before\n0 for exit" << endl;
        cin >> c;
        if(c==1)
        {
            cout << "Enter the new element :" << endl;
            cin >> item ;
            insert_first(item);
            cout << endl << endl << "Now printing " << endl;
            travers();
        }
        else if(c==2)
        {
            cout << "Enter the new element :" << endl;
            cin >> item ;
            insert_last(item);
            cout << endl << endl << "Now printing " << endl;
            travers();
        }
        else if(c==3)
        {
            int e;
            cout << "Enter the element after which have to add the new element :" << endl;
            cin >> e >> item;
            insert_after(item,e);
            cout << endl << endl << "Now printing " << endl;
            travers();
        }
        else if(c==4)
        {
            int e;
            cout << "Enter the element after which have to add the new element :" << endl;
            cin >> e >> item;
            insert_before(item,e);
            cout << endl << endl << "Now printing " << endl;
            travers();
        }
        else if(c == 0)
            break;
    }
    return 0;
}
