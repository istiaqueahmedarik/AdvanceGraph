#include <bits/stdc++.h>
using namespace std;

class Krushkal
{
    multimap<int, pair<int, int>> m;
    map<int, int> parent;

public:
    void addEdges(int u, int v, int w)
    {
        m.insert({w, {u, v}});
        parent[u] = u;
        parent[v] = v;
    }
    int findRep(int u) { return parent[u] == u ? u : parent[u] = findRep(parent[u]); }
    bool Union(int u, int v)
    {
        int x = findRep(u);
        int y = findRep(v);
        if (x != y)
        {
            parent[x] = y;
            return true;
        }
        return false;
    }
    vector<pair<int, int>> kruskal()
    {
        vector<pair<int, int>> ans;
        for (auto i : m)
        {
            if (Union(i.second.first, i.second.second))
            {
                ans.push_back({i.second.first, i.second.second});
            }
        }
        return ans;
    }
};

int main()
{
    Krushkal k;
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        k.addEdges(a, b, c);
    }
    vector<pair<int, int>> ans = k.kruskal();
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}