#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements (must be even): ";
    cin >> n;

    int q[100], result[100];

    cout << "Enter queue elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    int mid = n / 2;
    int i = 0;
    int j = mid;
    int k = 0;

    while (i < mid && j < n)
    {
        result[k++] = q[i++];
        result[k++] = q[j++];
    }

    cout << "\nInterleaved Queue:\n";
    for (int x = 0; x < n; x++)
    {
        cout << result[x] << " ";
    }

    return 0;
}
