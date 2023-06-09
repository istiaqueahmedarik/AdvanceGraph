#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int mod = 1e9 + 7;
int m, n;
vector<string> v;
int vis[1001][1001];
int newx[4] = {-1, 1, 0, 0};
int newy[4] = {0, 0, 1, -1};
int c = 0;
bool valid(int i, int j)
{
    if (vis[i][j] == 1)
        return false;
    if (i >= 0 and i < n and j >= 0 and j < m)
        return true;
    return false;
}
void dfs(int i, int j)
{
    c++;
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int tx = i + newx[k];
        int ty = j + newy[k];

        if (valid(tx, ty) and v[tx][ty] == '.' and v[tx][ty] != '#')
        {
            dfs(tx, ty);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        memset(vis, 0, sizeof(vis));
        c = 0;
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 and v[i][j] == '@')
                {
                    dfs(i, j);
                }
            }
        }
        cout << c << endl;
    }
}