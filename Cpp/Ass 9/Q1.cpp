#include <iostream>
#include <queue>
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

void bfs(int start)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
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

    bfs(start);

    return 0;
}