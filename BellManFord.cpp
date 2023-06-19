#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[100005];
int dist[100005], n, e, parent[100005];
void Relaxing()
{
    for (int i = 1; i <= n; i++)
        for (auto j : adj[i])
            if (dist[i] + j.second < dist[j.first])
                dist[j.first] = dist[parent[j.first] = i] + j.second;
}

void init()
{
    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX;
}
void bellman(int src)
{
    init();
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++)
        Relaxing();
}
void pathPrint(int src, int dest)
{
    bellman(src);
    stack<int> s;
    while (dest != src)
    {
        s.push(dest);
        dest = parent[dest];
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
bool negativeCycle()
{
    for (int i = 1; i <= n; i++)
        for (auto j : adj[i])
            if (dist[i] + j.second < dist[j.first])
                return 1;
    return 0;
}
int main()
{
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src, des;
    cin >> src >> des;
    bellman(src);
    for (int i = 1; i <= n; i++)
        dist[i] == INT_MAX ? cout << "INF" : cout << dist[i] << " ";
    cout << endl;
    pathPrint(src, des);
}