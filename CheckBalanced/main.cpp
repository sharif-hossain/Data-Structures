#include <iostream>
#include<stack>
#include<string>
using namespace std;

bool IsPaired(char opening, char closing)
{
    if(opening=='(' && closing==')') return true;
   else if(opening =='{' && closing == '}') return true;
    if(opening == '[' && closing==']') return true;

        return false;
}
bool CheckBalanced(string exp)
{
    stack<char> S;

    for(int i = 0; i<exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] =='{' || exp[i] == '[')
        {
            S.push(exp[i]);
        }
        else if(exp[i] ==')' || exp[i] =='}' || exp[i] == ']')
        {
            if(S.empty() || !IsPaired(S.top(), exp[i]))
            {
                return false;
            }
            else{
                S.pop();
            }
        }
    }
    return S.empty() ? true:false;
}
int main()
{
    string exp;
    cout << "Enter expression : ";
    cin>>exp;

    bool result = CheckBalanced(exp);
    if(result == 1) cout << "Balanced";
    else if(result == 0) cout << "Not balanced"<<endl;
     /*   if(CheckBalanced(exp))
    {
        cout << "Balanced"<<endl;
    }
    else{
        cout << "Not balanced" << endl;
    }  */

    return 0;
}
