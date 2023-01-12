// MST Kruskal - Using DSU - O(MlogN)

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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

vector<int> parent, rankx;
vector<bool> vis;
vvi g;
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
    int u, v;
    ll weight;
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
        while (m--)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            Edge temp1, temp2;
            temp1.u = a, temp1.v = b, temp1.weight = -c;
            temp2.u = b, temp2.v = a, temp2.weight = -c;
            edges.pb(temp1);
            edges.pb(temp2);
        }
        parent.clear();
        rankx.clear();
        parent.resize(n);
        rankx.resize(n);
        for (int i = 0; i < n; i++)
            make_set(i);
        sort(edges.begin(), edges.end());
        bool flag = false;
        ll cost = LLONG_MAX;
        for (Edge e : edges)
        {
            if (find_set(e.u) != find_set(e.v))
            {
                union_sets(e.u, e.v);
                cost = min(cost, -e.weight);
                if (find_set(0) == find_set(n - 1))
                {
                    cout << cost << nl;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
            cout << -1 << nl;
    }
    return 0;
}
