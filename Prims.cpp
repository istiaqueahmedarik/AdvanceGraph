#include <bits/stdc++.h>
using namespace std;

class Prims
{
    map<int, vector<pair<int, int>>> graph;
    map<int, int> visited;

public:
    void addEdge(int u, int v, int w)
    {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> path(pair<int, int> start)
    {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost vs node
        pq.push({start.second, start.first});
        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            if (visited[curr.second])
                continue;
            visited[curr.second] = 1;
            ans.push_back(curr.second);
            for (auto i : graph[curr.second])
            {
                if (visited[i.first])
                    continue;
                pq.push({i.second, i.first});
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
    int srcU, mn = INT_MAX;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < mn)
        {
            mn = w;
            srcU = u;
        }
        p.addEdge(u, v, w);
    }

    vector<int> ans = p.path({srcU, 0}); // (node, cost)
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}