#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX];
bool visited[MAX];
int n, m;

void createGraph()
{
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void dfsIterative(int start)
{
    for (int i = 0; i < n; i++)
        visited[i] = false;

    stack<int> st;
    st.push(start);
    visited[start] = true;

    cout << "DFS Traversal (using stack): ";

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        cout << node << " ";

        for (int i = n - 1; i >= 0; i--)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                st.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

int main()
{
    createGraph();

    int start;
    cout << "Enter start node: ";
    cin >> start;

    dfsIterative(start);

    return 0;
}