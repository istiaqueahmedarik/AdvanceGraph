#include <bits/stdc++.h>
using namespace std;
class Krushkal
{
    vector<pair<int, pair<int, int>>> edges;
    int parent[100];

public:
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
        parent[u] = u;
        parent[v] = v;
    }
    // int findRep(int x)
    // {
    //     if (x == parent[x])
    //         return x;
    //     return findRep(parent[x]);
    // }
    int findRep(int x) { return x == parent[x] ? x : parent[x] = findRep(parent[x]); }
    bool Uninon(int u, int v)
    {
        if (findRep(u) != findRep(v))
        {
            parent[u] = v;
            return true;
        }
        return false;
    }
    vector<pair<int, pair<int, int>>> paths()
    {
        vector<pair<int, pair<int, int>>> ans;
        sort(edges.begin(), edges.end());
        for (int i = 0; i < edges.size(); i++)
        {
            if (Uninon(edges[i].second.first, edges[i].second.second))
            {
                ans.push_back(edges[i]);
            }
        }
        return ans;
    }
};
int main()
{
    int edges;
    cin >> edges;
    Krushkal k;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        k.addEdge(u, v, w);
    }
    vector<pair<int, pair<int, int>>> ans = k.paths();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second.first << " " << ans[i].second.second << " " << ans[i].first << endl;
    }
}