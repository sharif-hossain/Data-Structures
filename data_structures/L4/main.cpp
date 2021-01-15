#include <iostream>

using namespace std;

class node
{
public:
    int info;
    node *link;
};
node *head=NULL, *tmp, *pre;

void ins(int data)
{
    node *ptr;
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
void tra()
{
    node *str;
    str = head;
    while(str != NULL)
    {
        cout << str -> info << endl;
        str = str -> link;
    }
}
void first()
{
    node *srt;
    srt = head;
    head = srt -> link;
}
void last()
{
    node *srt;
    srt = head;
    while(srt!= NULL)
    {
        if(srt -> link == NULL)
        {
            tmp -> link = NULL;
            break;
        }
        else
        {
            tmp = srt;
            srt = srt -> link;
        }
    }
}
void giv(int item)
{
    node *srt;
    srt = head;
    while(srt != NULL)
    {
        if(srt -> info == item )
        {
            tmp -> link = srt -> link;
            break;
        }
        else
        {
            tmp = srt;
            srt = srt -> link;
        }
    }
}
void after (int item)
{
    node *srt;
    srt = head;
    while(srt != NULL)
    {
        if(srt -> info == item)
        {
            tmp = srt -> link;
            srt -> link = tmp -> link;
           // cout << "temp " << tmp -> info << endl;
            //cout << "srt " << srt -> info << endl;
            break;
        }
        else
           {
               srt = srt -> link;
           }
    }
}
void before (int item)
{
    node *srt;
    srt = head;
    while (srt != NULL)
    {
        if(srt -> info == item)
        {
            pre -> link = srt;
            cout << srt -> info << endl;
            cout << pre -> info << endl;
            break;
        }
        else
        {
            //cout << tmp -> info << endl;
           pre = tmp;
           tmp = srt;

            srt = srt -> link;
        }

    }
}

int main()
{
    int n,item,c;
    cout << "Enter how many element :" << endl;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> item;
        ins(item);
    }
    cout << "Operation ?" << endl;

    while(1)
    {
        cout << "1 for delete 1st node\n2 for last node\n3 for given node\n4 for after a node\n5 for before a node\n0 for exit " << endl;
        cin >> c;
        if(c==1)
        {
            first();
        }
        else if(c==2)
        {
            last();
        }
        else if(c==3)
        {
            int item;
            cout << "Enter the element :" ;
            cin >> item;
            giv(item);
        }
        else if(c==4)
        {
            int item;
            cout << "Enter the element :" ;
            cin >> item;
            after(item);
        }
        else if(c==5)
        {
            int item;
            cout << "Enter the element : " ;
            cin >> item;
            before (item);
        }
        else
            break;

        cout << "Existing elements in list:" << endl;
        tra ();
        cout << endl;
    }
    return 0;
}
