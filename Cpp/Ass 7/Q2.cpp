#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void improvedSelectionSort(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted Array using Improved Selection Sort: ";
    printArray(arr, n);

    return 0;
}
