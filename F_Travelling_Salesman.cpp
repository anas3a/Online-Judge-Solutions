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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges;

        int cost = 0;
        vector<Edge> result;
        parent.clear();
        rankx.clear();
        parent.resize(n + 1);
        rankx.resize(n + 1);
        for (int i = 1; i <= n; i++)
            make_set(i);

        for (int i = 0; i < m; i++)
        {
            Edge tmp;
            cin >> tmp.u >> tmp.v >> tmp.weight;
            edges.pb(tmp);
            swap(tmp.u, tmp.v);
            edges.pb(tmp);
        }
        sort(edges.begin(), edges.end());
        ll ans = 0;
        for (Edge e : edges)
        {
            if (find_set(e.u) != find_set(e.v))
            {
                cost += e.weight;
                ans = max(ans, (ll)e.weight);
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
