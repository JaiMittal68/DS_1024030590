// Q2

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7 - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}