#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;
int cnt, mxsz;

void make_set(int u)
{
    parent[u] = u;
    sz[u] = 1;
}
int find_set(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
}
void make_set(int a, int b)
{
    int ax = find_set(a);
    int bx = find_set(b);
    if (ax != bx)
    {
        cnt--;
        if (sz[ax] < sz[bx])
            swap(ax, bx);
        sz[ax] += sz[bx];
        parent[bx] = ax;
        mxsz = max(mxsz, sz[ax]);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    cnt = n;
    mxsz = 1;
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++)
        make_set(i);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        make_set(a, b);
        cout << cnt << " " << mxsz << endl;
    }
}