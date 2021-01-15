// Include all the required files
#include<iostream>
#include<stack>
#include<string>

// Define the namespace for standard library
using namespace std;

// Check weather the given character is an opening bracket or not
// Return true if it is an opening bracket else return false.
int IsOpeningBracket(char openbracket)
{
    return (openbracket=='('||openbracket=='{'||openbracket=='[');
}

// Check weather the given character is a closing bracket or not
// Return true if it is an closing bracket else return false.
int IsClosingBracket(char closedbracket)
{
    return (closedbracket==')'||closedbracket=='}'||closedbracket==']');
}

// Check weather the given character is a number or not
// Return true if it is a number else return false.
bool IsNumber(char C)
{
    // Subtract the ascii value of 0 to get the real value of the
    // numbers
    //return ((int)num-'0'>=0 && (int)num-'0'<=9);
     if(C>='0' && C<='9') return true;
    if(C>='a' && C<='z') return true;
    if(C>='A' && C<='Z') return true;
    else return false;
}

// Check weather the character is Operator or not.
// Return true if it is an operator else return false.
int IsOperator(char op)
{
    // All the supported operators
    return (op=='+'||op=='-'||op=='*'||op=='/'||op=='^');
}

// Give the precedence value of the character or operator
// Return the provided precedence value.
int PrecedenceValue(char a)
{
    // Since the operators are less so I implemented the if-else
    // loop. However if you want to make the precedence table of all
    // operators then make a hash table for it.
    // Map the operator to a value in that hash table.
    if(a=='^')
    {
        return 3;
    }
    else if(a=='*'||a=='/')
    {
        return 2;
    }
    else if(a=='+'||a=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Operator Precedence Check
// If precedence of first operator is greater than other then return true
// else return false.
int CheckPrecedence(char first_op, char second_op)
{
    // Check the precedence value of first operator and second operator
    // If the precedence value of first operator is greater then
    // return true else return false.
    return (PrecedenceValue(first_op)>PrecedenceValue(second_op));
}

// Convert the infix expression to postfix expression according to
// an algorithm.
// Return the postfix expression in the form of string if valid
// else return the error message.
string ConvertPostfix(string infix)
{
    int i;  // Variable declarations
    char mychar;
    string postfix="";
    stack<char> char_stack;

    for(i=0; i<infix.length(); i++) // Iterate through all the characters
    {
        mychar=infix[i];  // temp_storage

        if(IsOpeningBracket(mychar))
        {
            // If the character is opening bracket then push it onto stack.
            char_stack.push(mychar);
        }
        else if(IsClosingBracket(mychar))
        {
            // If it is closing bracket then then do the following things from the
            // stack.
            // 1. Pop all elements until opening bracket is encountered or stack
            // becomes empty.
            while(!IsOpeningBracket(char_stack.top()))
            {
                postfix+=char_stack.top();
                char_stack.pop();
                if(char_stack.empty()) break;
            }
            // 2. Popping the opening bracket after handling segmentation fault.
            if(!char_stack.empty())
            {
                char_stack.pop();
            }
        }
        else if(IsNumber(mychar))
        {
            // If the character is a number.
            postfix+=mychar;
        }
        else if(IsOperator(mychar))
        {
            // If the chacter is an operator then do this.
            if(char_stack.empty()||IsOpeningBracket(char_stack.top()))
            {
                char_stack.push(mychar);
                continue;
            }

            // Check for the precedence first then do the approprite thing.
            if(CheckPrecedence(mychar,char_stack.top()))
            {
                char_stack.push(mychar);
            }
            else
            {
                while(!IsOpeningBracket(char_stack.top()))
                {
                    postfix+=char_stack.top();
                    char_stack.pop();
                    if(char_stack.empty()) break;
                }
                char_stack.push(mychar);
            }
        }
        else
        {
            // If the expression contain some invalid symbols then print an error.
            return "Invalid Symbols in expressions!!";
        }
    }

    // If the stack is still not empty and contain some characters then do this.
    while(!char_stack.empty())
    {
        postfix+=char_stack.top();
        char_stack.pop();
    }

    return postfix;
} // End of Infix to Postfix expression

int main()
{
    string exp;
    cout << "Enter infix expression: \n";
    //getline(cin, exp);
    cin >> exp;

    string result = ConvertPostfix(exp);
    cout << "Postfix expression: " << result << "\n";
    return 0;
}
