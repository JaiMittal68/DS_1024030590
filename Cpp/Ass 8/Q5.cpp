#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* ================= MAX HEAP (for Increasing Order) ================= */

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        maxHeapify(arr, n, largest);
    }
}

void heapSortIncreasing(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);

        maxHeapify(arr, i, 0);
    }
}

/* ================= MIN HEAP (for Decreasing Order) ================= */

void minHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortDecreasing(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);

        minHeapify(arr, i, 0);
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

    int choice;
    cout << "\n1. Heapsort in INCREASING order";
    cout << "\n2. Heapsort in DECREASING order";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        heapSortIncreasing(arr, n);
        cout << "Sorted array (Increasing): ";
        printArray(arr, n);
    }
    else if (choice == 2)
    {
        heapSortDecreasing(arr, n);
        cout << "Sorted array (Decreasing): ";
        printArray(arr, n);
    }
    else
    {
        cout << "Invalid choice.\n";
    }

    return 0;
}
