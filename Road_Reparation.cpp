#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

struct dt
{
    int a, b, cost;
};
bool comp(dt &a, dt &b)
{
    return a.cost < b.cost;
}
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
        if (sz[ax] < sz[bx])
            swap(ax, bx);
        sz[ax] += sz[bx];
        parent[bx] = ax;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++)
        make_set(i);
    vector<dt> v(m);
    for (auto &i : v)
        cin >> i.a >> i.b >> i.cost;
    sort(v.begin(), v.end(), comp);
    long long cost = 0;
    for (auto &i : v)
    {
        if (find_set(i.a) != find_set(i.b))
        {
            cost += i.cost;
            make_set(i.a, i.b);
        }
    }
    int x = find_set(1);
    if (sz[x] < n)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << cost << endl;
}