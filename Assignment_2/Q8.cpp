// Q8

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int distinct = 0;
    for (int i = 0; i < n; i++)
    {
        bool repeat = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                repeat = true;
                break;
            }
        }
        if (!repeat)
            distinct++;
    }
    cout << distinct;
}