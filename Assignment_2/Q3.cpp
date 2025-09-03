#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == arr[0] + mid) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return arr[0] + start;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};  // missing number is 5
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number is: " << findMissingNumber(arr, n) << endl;

    return 0;
}
