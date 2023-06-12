#include <bits/stdc++.h>
using namespace std;
bool operator<(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
bool operator>(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
class Prims
{
    map<int, vector<pair<int, int>>> adj; // u->v,w;
    map<int, int> visited;

public:
    void addEdges(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> prims(int src)
    {
        priority_queue<pair<int, int>> pq;
        pq.push({src, 0});
        vector<int> ans;
        while (!pq.empty())
        {
            pair<int, int> Top = pq.top();
            pq.pop();
            if (visited[Top.first])
                continue;
            visited[Top.first] = 1;
            ans.push_back(Top.first);
            for (auto i : adj[Top.first])
            {
                if (!visited[i.first])
                    pq.push({i.first, i.second});
            }
        }
        return ans;
    }
};
int main()
{
    Prims p;
    int edges;
    cin >> edges;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        p.addEdges(u, v, w);
    }
    vector<int> ans = p.prims(1);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
