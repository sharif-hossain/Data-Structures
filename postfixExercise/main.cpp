#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
int EvaluatePostfix(string exp);
int PerformOperation(char operation, int op1, int op2);
bool IsOperator(char C);
bool IsNumeric(char C);
*/

bool IsOperand(char C)
{
    if(C >= '0' && C <= '9')
    {
        return true;
    }
    return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
    {
        return true;
    }
    return false;
}
int PerformOperation(char operation, int op1, int op2)
{
    if(operation == '+') return op1+op2;
    else if(operation == '-') return op1 - op2;
    else if(operation == '*') return op1*op2;
    else if(operation == '/') return op1/op2;
    else cout << "Error";
    return -1;
}
int EvaluatePostfix(string exp)
{
    stack<int> S;

    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if(IsOperand(exp[i]))
        {
            int operand = 0;
            while(IsOperand(exp[i]))
            {
                operand = (operand*10) + (exp[i] - '0');
                i++;
            }
            S.push(operand);
        }
        else if(IsOperator(exp[i]))
        {
            int op1, op2, result;
           op2 = S.top();
            S.pop();
           op1 = S.top();
            S.pop();
            result = PerformOperation(exp[i], op1, op2);
            S.push(result);
        }
    }
    return S.top();
}
int main()
{
    string exp;
    cout << "Enter postfix expression \n";
    getline(cin, exp);

    int result = EvaluatePostfix(exp);
    cout << "Result = " << result << "\n";
    //return 0;
}
/*
int EvaluatePostfix(string exp)
{
    stack<int> S;
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ' || exp[i] == ',')
        {
            continue;
        }
        else if(IsOperator(exp[i]))
        {
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();

            int result = PerformOperation(exp[i], operand1, operand2);
            S.push(result);
        }
        else if(IsNumeric(exp[i]))
        {
            int operand = 0;
            while(i < exp.length() && IsNumeric(exp[i]))
            {
                operand = (operand*10) + (exp[i] - '0');
                i++;
            }
            i--;
            S.push(operand);
           // S.push(exp[i]);
        }
    }
 return S.top();
}
bool IsNumeric(char C)
{
    if(C >= '0' && C <= '9')
    {
        return true;
    }
    return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/')
    {
        return true;
    }
    return false;
}

int PerformOperation(char operation, int op1, int op2)
{
    if(operation == '+') return op1+op2;
    else if(operation == '-') return op1 - op2;
    else if(operation == '*') return op1*op2;
    else if(operation == '/') return op1/op2;
    else cout << "Error";
    return -1;
}
*/
