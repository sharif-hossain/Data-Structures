#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

void Reverse(char c[], int n)
{
    stack<char> S;

    // loop for push
    for(int i = 0; i < n; i++)
    {
        S.push(c[i]);
    }

    //pop
    for(int i = 0; i < n; i++)
    {
        c[i] = S.top(); // overwrite character at index i.
        S.pop();
    }
}
int main()
{
    char c[51];
    cout << "Enter a string : ";
    gets(c);
    Reverse(c, strlen(c));
    cout << c << endl;
    return 0;
}
