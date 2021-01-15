#include<bits/stdc++.h>
using namespace std;

int Partition(int arr[],int start,int end)
{
    int pivot=arr[end];

    int P_index = start;
    int i,temp;

    for(i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            /* t=arr[i];
             a[i]=a[P_index];
             a[P_index]=t;
             P_index++;  */
            swap(arr[i], arr[P_index]);
            P_index++;
        }
    }

    /* temp=arr[end];
     arr[end]=arr[P_index];
     arr[P_index]=temp;  */

    swap(arr[P_index], arr[end]);
    return P_index;
}
void Quicksort(int *A,int start,int end)
{
    if(start < end)
    {
        int P_index = Partition(A, start, end);
        Quicksort(A, start, P_index - 1);
        Quicksort(A, P_index + 1, end);
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements:\n";
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    Quicksort(arr, 0, n-1);
    //cout<<"After Quick Sort the array is:\n\n";
    for(int i=0; i<n; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}
