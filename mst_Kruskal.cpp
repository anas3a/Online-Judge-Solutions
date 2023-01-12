#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

vector<int> parent, rankx;

void make_set(int v)
{
    parent[v] = v;
    rankx[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rankx[a] < rankx[b])
            swap(a, b);
        parent[b] = a;
        if (rankx[a] == rankx[b])
            rankx[a]++;
    }
}

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

void kruskal()
{
    int n;
    vector<Edge> edges;

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rankx.resize(n);

    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (find_set(e.u) != find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}