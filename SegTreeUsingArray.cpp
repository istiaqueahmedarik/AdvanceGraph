#include <bits/stdc++.h>
using namespace std;
int arr[100];
int tree[400];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (start + end) >> 1;
    build(left, start, mid);
    build(right, mid + 1, end);
    tree[node] = tree[left] + tree[right];
}

int QuerySum(int left, int right, int node, int start, int end)
{
    // we will break the range and if find sub seg add them with the ans;
    if (end < left || start > right)
        return 0; // range er baire
    if (start >= left && end <= right)
        return tree[node];  // sub segment or probably full segment
    int Left = (node << 1); // need more breaking
    int Right = (node << 1) + 1;
    int mid = (start + end) >> 1;
    int val1 = QuerySum(left, right, Left, start, mid);
    int val2 = QuerySum(left, right, Right, mid + 1, end);
    return val1 + val2;
}
void Update(int index, int value, int node, int start, int end)
{
    if (start > index || end < index)
        return;
    if (start == end && start == index)
    {
        tree[node] = value;
        return;
    }
    int Left = (node << 1);
    int Right = (node << 1) + 1;
    int mid = (start + end) >> 1;
    Update(index, value, Left, start, mid);
    Update(index, value, Right, mid + 1, end);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }
    build(1, 0, 99);
    cout << QuerySum(2, 3, 1, 1, 100) << endl;
    Update(2, 10, 1, 1, 100);
    cout << QuerySum(2, 3, 1, 1, 100);
}