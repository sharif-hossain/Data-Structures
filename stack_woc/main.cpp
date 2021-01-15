#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node * link;
};

Node * top;

void Push(int x)
{
    // struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    Node* temp = new Node();
    temp->data=x;
    temp->link=top;
    top=temp;
}

void Pop()
{
    Node * temp;
    if(top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);
}

int IsEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int Top()
{
    return(top->data);
}

void Print()
{
    Node * temp = top;
    if(temp==NULL)
    {
        printf("Hey ! Stack is empty..\n");
        return;
    }
    printf("Stack : \n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    top=NULL;

    Push(2);
    Push(4);
    Push(7);
    Print();
    Pop();
    Print();
    Push(6);
    Print();

    printf("\nIs stack empty ?\n");
    if(IsEmpty())
        cout << "Yes" << endl;
    else
        printf("No\n");

    int top_data = Top();
    printf("\nData at the top of stack = %d\n",top_data);

    return 0;
}
