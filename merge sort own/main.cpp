#include <iostream>
#include <conio.h>
using namespace std;

class golap
{
    int a[100], number_of_data;
public:
    golap();
    void merge_sort();
    void display();
}g;

golap::golap()
{
    cout<<"Number of data: ";
    cin>>number_of_data;
    cout<<"Enter data:\n";
    for(int i=0; i<number_of_data; i++)
        cin>>a[i];
    merge_sort();
}

void golap::merge_sort()
{
    int cnt = 1;
    for(int i=0; i<number_of_data; i++)
    {
        cnt = (cnt*2 > number_of_data)? number_of_data : cnt*2;
        cout<<"Compareing loc: "<< i+1 << " to " << cnt << endl;

        for(int j=i; j<cnt; j++)
        {

            for(int k=i; k<cnt; k++)
            {
                if(a[i] < a[k])
                {
                    a[i] = a[i] + a[k];
                    a[k] = a[i] - a[k];
                    a[i] = a[i] - a[k];
                }
            }
        }
    }

    display();
}

void golap::display()
{
    for(int i=0; i<number_of_data; i++)
        cout<<a[i] <<' ';
}

main(){}
