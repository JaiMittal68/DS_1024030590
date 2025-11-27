#include <iostream>
using namespace std;

#define MAXQ 1000

char q[MAXQ];
int frontQ = 0, rearQ = -1;

bool isEmpty()
{
    return (frontQ > rearQ);
}

void enqueue(char ch)
{
    if (rearQ == MAXQ - 1)
    {
        cout << "Queue overflow!" << endl;
        return;
    }
    rearQ++;
    q[rearQ] = ch;
}

char dequeue()
{
    if (isEmpty())
    {
        return '\0';
    }
    char ch = q[frontQ];
    frontQ++;
    return ch;
}

char frontElement()
{
    if (isEmpty())
        return '\0';
    return q[frontQ];
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char ch;
    int freq[256] = {0};

    cout << "Enter characters (separated by space):\n";

    for (int i = 0; i < n; i++)
    {
        cin >> ch;

        freq[(unsigned char)ch]++;

        enqueue(ch);

        while (!isEmpty() && freq[(unsigned char)frontElement()] > 1)
        {
            dequeue();
        }

        if (isEmpty())
        {
            cout << "-1 ";
        }
        else
        {
            cout << frontElement() << " ";
        }
    }

    return 0;
}
