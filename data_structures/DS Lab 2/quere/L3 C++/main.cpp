//For many students and many subjects

#include <iostream>

using namespace std;

class stu
{
    double marks [1000];
    void calculate (int);
public :
    int roll[100];
    void input (int n);
    void read(int);
    double maximum =0.0;
    int r1,r2;
    double minimum;

} s[10];

void stu :: input (int n)
{
    for(int i=0;i<n;i++)
    {
        cin >> roll[i] >> marks[i];
    }
}

void stu :: read (int n)
{
    calculate(n);
}
void stu :: calculate (int n)
{

    for(int i=0; i<n; i++)
    {
        if(marks[i]>maximum)
        {
            r1=roll[i];
            maximum=marks[i];
        }

    }
    double mm=maximum;
    for(int i=0; i<n; i++)
    {
        if(marks[i]<mm)
        {
            r2=roll[i];
            mm = marks[i];
        }
    }
    minimum = mm;
}

int main()
{
    int n,sub;
    cout << "Enter how many subjects :" << endl;
    cin >> sub;
    cout << "Enter how many students :" << endl;
    cin >> n;

    for(int i=0; i<sub; i++)
    {
        cout << "Enter roll and marks for the " << i+1 << " th subject " << endl;
        s[i].input(n);
        s[i].read(n);
    }

    for(int i =0; i<sub; i++)
    {
        cout << "For the " << i+1 << "th subject " << endl;
        cout << "Roll " << s[i].r1 << " Maximum " << s[i].maximum << endl;
        cout << "Roll " << s[i].r2 << " Minimum " << s[i].minimum << endl;
    }

    return 0;
}
