#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[100005];
bool operator>(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool operator<(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
int dist[100005];
void init()
{
    for (int i = 0; i < 100005; i++)
        dist[i] = 1e9;
}
void relax(int u, int v, int w, priority_queue<pair<int, int>> &pq)
{
    if (dist[u] + w < dist[v])
    {
        dist[v] = dist[u] + w;
        pq.push({v, dist[v]});
    }
}
void DijkStra(int src)
{
    init();
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({src, 0});
    while (!pq.empty())
    {
        int node = pq.top().first;
        pq.pop();
        for (auto i : adj[node])
        {
            relax(node, i.first, i.second, pq);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src;
    cin >> src;
    DijkStra(src);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << endl;
}