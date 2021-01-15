#include <iostream>

using namespace std;

int linear_search(int arr[], int n, int value)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    // int arr[] = {3, 55, 41, 4, 11, 5, 14, 9, 53, 77};
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the array elements:\n";
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }

    int value;

    cout << "Enter a value to find: " << endl;

    cin >> value;
    int result = linear_search(arr, n, value);

    if(result >= 0)
    {
        cout << "The number " << arr[result] << " was found at the element with index " << result << endl;
    }
    else
    {
        cout << "The number " << value << " was not found." << endl;
    }
    return 0;
}
