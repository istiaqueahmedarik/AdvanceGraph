#include <bits/stdc++.h>
using namespace std;
int arr[100];
int tree[500];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int RangeSum(int node, int start, int end, int l, int r)
{
    if (l >= start && r <= end)
        return tree[node];
    if (l > end || r < start)
        return 0;
    int mid = (l + r) >> 1;
    return RangeSum(2 * node, start, end, l, mid) + RangeSum(2 * node + 1, start, end, mid + 1, r);
}
void Update(int node, int start, int end, int idx, int val)
{
    if (start > idx || end < idx)
        return;
    if (start == idx)
        tree[start] = val;
    int mid = (start + end) >> 1;
    Update(2 * node, start, mid, idx, val);
    Update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    cout << RangeSum(1, 2, 3, 0, n - 1) << endl;
}