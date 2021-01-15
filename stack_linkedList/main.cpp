
// Stack - Object oriented implementation using linked_list
#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int data;
    Stack* link;
public:
    /*
    //Not used constructor because not declared as local variable to class
    Stack()
    {
        Stack* top = NULL; // for empty list, set top = NULL.
    }
    */
    // Push operation to insert an element on top of stack/beginning of list.
    Stack *top = NULL;
    void Push(int x)
    {
        Stack* temp = new Stack();
        temp->data = x;
        temp->link = top;
        top = temp;
    }

    // Pop operation to remove an element from top of stack/beginning of list.
    void Pop()
    {
        if(top == NULL)
            return;
        Stack* temp;
        temp = top;
        top = temp->link;
        delete(temp);
    }

    // Top operation to return element at top of stack/beginning of list.
    int Top()
    {
        return top->data;
    }

    // This function will return (true) if stack is empty, (false) otherwise
    bool IsEmpty()
    {
        if (top == NULL)
            return true;
        return false;
    }

    // ONLY FOR TESTING - NOT A VALID OPERATION WITH STACK
    // This function is just to test the implementation of stack.
    // This will print all the elements in the stack at any stage.
    void Print()
    {
        printf("Stack: ");
        Stack* temp = top;
        while(temp != NULL)
        {
            cout << temp-> data << " ";
            temp = temp->link;
        }
        printf("\n");//it works in latest c++ versions

    }
};

int main()
{
    // Code to test the implementation.
    // calling Print() after each push or pop to see the state of stack.
    Stack S;
    S.Push(2);
    S.Print();
    S.Push(5);
    S.Print();
    S.Push(10);
    S.Print();
    S.Pop();
    S.Print();
    S.Push(12);
    S.Print();
}
