#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool IsOperand(char C)
{
    if(C>='0' && C<='9') return true;
    else if(C>='a' && C<='z') return true;
    else if(C>='A' && C<='Z') return true;
    else
        return false;
}
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}
int getPrecedence(char op)
{
    int preced = -1;
    switch(op)
    {
    case '+':
    case '-':
        preced = 1;
        break;
    case '*':
    case '/':
        preced = 2;
        break;
    case '$':
        preced = 3;
        break;
    }
    return preced;
}
bool IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}
bool HasHighPrecedence(char op1, char op2)
{
   int op1Preced = getPrecedence(op1);
   int op2Preced = getPrecedence(op2);

   if(op1Preced == op2Preced)
   {
       if(IsRightAssociative(op1)) return false;
       return true;
   }
   return op1Preced > op2Preced ? true : false;
}
string PostfixExpression(string exp)
{
    stack<char> S;
    string postfix = "";
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ' || exp[i] == ',') continue;
        else if(IsOperand(exp[i]))
        {
            postfix+= exp[i];
        }
        else if(IsOperator(exp[i]))
        {
            while(!S.empty() && HasHighPrecedence(S.top(), exp[i]))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
    }
    while(!S.empty())
    {
        postfix+= S.top();
        S.pop();
    }
    return postfix;
}
int main()
{
    string exp;
    cout << "Enter infix expression: \n";
    getline(cin, exp);

    string result = PostfixExpression(exp);
    cout << "Postfix expression: " << result << "\n";
    return 0;
}
