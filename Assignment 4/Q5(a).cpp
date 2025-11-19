#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() { return q1.empty(); }

    int size() { return q1.size(); }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        queue<int> temp = q1;
        cout << "Top -> ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackTwoQueues st;
    int choice, x;
    while (true) {
        cout << "\n1.push 2.pop 3.top 4.isEmpty 5.size 6.display 7.exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> x; st.push(x); break;
            case 2: st.pop(); break;
            case 3: {
                int t = st.top();
                if (t != -1) cout << t << "\n";
                break;
            }
            case 4: cout << (st.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 5: cout << st.size() << "\n"; break;
            case 6: st.display(); break;
            case 7: return 0;
            default: cout << "Invalid\n";
        }
    }
    return 0;
}
