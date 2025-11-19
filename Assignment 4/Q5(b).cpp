#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool isEmpty() { return q.empty(); }

    int size() { return q.size(); }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        queue<int> temp = q;
        cout << "Top -> ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};

int main() {
    StackOneQueue st;
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
