#include<iostream>
using namespace std;

void Merge(int left[], int right[], int arr[], int nL, int nR)
{

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nL && j < nR)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i = i + 1;
        }
        else
        {
            arr[k] = right[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < nL)
    {
        arr[k] = left[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < nR)
    {
        arr[k] = right[j];
        j = j + 1;
        k = k + 1;
    }
}

void MergeSort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    MergeSort(left, mid);
    MergeSort(right, n - mid);
    Merge(left, right, arr, mid, n - mid);
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "enter number of data to be sorted: " ;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        //cout << "enter element " << i+1 << " : ";
        cin >> arr[i];
    }
    MergeSort(arr, n);
    PrintArray(arr, n);
    return 0;
}
