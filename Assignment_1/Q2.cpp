#include <iostream>
using namespace std;

int arr[100];
int n = 0;

void createArray()
{
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void displayArray()
{
    cout << "Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void remDupe()
{
    int newSize = 0;
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < newSize; j++)
        {
            if (arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    n = newSize;
    cout << "All duplicates removed. New size of array is " << n << ".\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. REMOVE DUPLICATES\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            createArray();
            break;
        case 2:
            displayArray();
            break;
        case 3:
            remDupe();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
