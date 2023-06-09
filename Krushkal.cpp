#include <bits/stdc++.h>
using namespace std;
class Krushkal
{
    multimap<int, pair<int, int>> edges;
    map<int, int> parents;

public:
    void addEdges(int u, int v, int w)
    {
        edges.insert({w, {u, v}});
        parents[u] = u;
        parents[v] = v;
    }
    int findRep(int u) { return u == parents[u] ? u : parents[u] = findRep(parents[u]); }
    bool Union(int u, int v)
    {
        int x = findRep(u);
        int y = findRep(v);
        if (x != y)
        {
            parents[u] = v;
            return true;
        }
        return false;
    }
    vector<pair<int, pair<int, int>>> MST()
    {
        vector<pair<int, pair<int, int>>> result;
        for (auto edge : edges)
        {
            if (Union(edge.second.first, edge.second.second))
            {
                result.push_back({edge.first, {edge.second.first, edge.second.second}});
            }
        }
        return result;
    }
};
int main()
{
    Krushkal k;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        k.addEdges(u, v, w);
    }
    vector<pair<int, pair<int, int>>> result = k.MST();
    int cost = 0;
    for (auto edge : result)
    {
        pair<int, pair<int, int>> p = edge;
        cout << p.second.first << " " << p.second.second << endl;
        cost += p.first;
    }
    cout << cost << endl;
}
/*
    9
    1 6 10
    6 5 25
    5 4 22
    4 3 12
    3 2 16
    2 1 28
    2 7 14
    7 5 24
    7 4 18
*/