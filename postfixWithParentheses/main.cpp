#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsOperand(char C)
{
    if(C>='0' && C<='9') return true;
    if(C>='a' && C<='z') return true;
    if(C>='A' && C<='Z') return true;
    return false;
}
bool IsOperator(char C)
{
    if(C=='+' || C=='-' || C=='*'||C=='/' || C=='#')
        return true;
    return false;
}

int IsOpeningBracket(char OB)
{
    return (OB=='(' || OB=='{'||OB=='[');
}
int IsClosingBracket(char CB)
{
    return (CB==')'||CB=='}'||CB==']');
}
int getWeight(char C)
{
    if(C=='^') return 3;
    else if(C=='*' || C== '/') return 2;
    else if(C=='+' || C=='-') return 1;
    else
    {
        return 0;
    }
}
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}
int HasHigherPriority(char op1, char op2)
{
   // return (getWeight(op1)>getWeight(op2));
   int op1Weight = getWeight(op1);
   int op2Weight = getWeight(op2);
   if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}
string EvaluatePostfix(string exp)
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
            while(!S.empty() && !IsOpeningBracket(S.top()) && HasHigherPriority(S.top(),exp[i]))
            {
                postfix += S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
        else if(IsOpeningBracket(exp[i]))
        {
            S.push(exp[i]);
        }
        else if(IsClosingBracket(exp[i]))
        {
            while(!S.empty()&& !IsOpeningBracket(S.top()))
            {
                postfix+= S.top();
                S.pop();
            }
            S.pop();
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
    cout << "Enter infix expression : " << endl;
    getline(cin, exp);
    string postfix = EvaluatePostfix(exp);
    cout << "postfix expression : " << postfix << endl;
    return 0;
}
