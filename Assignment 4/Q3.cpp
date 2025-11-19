#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave.\n";
        return;
    }

    queue<int> firstHalf;

    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // Input: 4 7 11 20 5 9
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << "\n";

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
