#include <iostream>
#include <stdio.h>
using namespace std;

void bs(int a[20], int d, int h)
{
    int l=0,m;

    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==d)
            break;

        else if(a[m]>d)
            h=m-1;

        else if(a[m]<d)
            l=m+1;
    }

    if(l>h)
        cout << "Element not found" << endl;

    else
        printf("Element %d found at location %d ",a[m],m+1);
}

int main()
{
    int a[20],h,d;
    cout << "How many element in array ? :";
    cin >> h;

    for(int i=0; i<h; i++)
        cin >> a[i];

    cout << "Which element do you want to find ? : " << "\n";
    cin >> d;

    bs(a,d,h);

    return 0;
}

// Sample Input : 1 2 3 4 5 6 7 8 9
//                6
// Sample Output : Element 6 found at location 6
