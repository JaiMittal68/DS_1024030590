#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue
{
private:
    queue<int> q;

public:
    bool empty()
    {
        return q.empty();
    }

    void push(int x)
    {
        int sz = q.size();
        q.push(x);

        for (int i = 0; i < sz; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty, cannot pop.\n";
            return;
        }
        q.pop();
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return q.front();
    }
};
