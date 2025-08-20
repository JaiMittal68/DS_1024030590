// Q1

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int element;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element: ";
    cin >> element;
    int low = 0;
    int high = n - 1;
    bool found = false;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (element == arr[mid])
        {
            cout << "Element found at index: " << mid;
            found = true;
            break;
        }
        else if (element < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (found == false)
    {
        cout << element << " is not present in the given array";
    }
}