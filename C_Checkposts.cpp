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

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v)
{
    used[v] = true;
    for (auto u : adj[v])
    {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
    {
        if (!used[u])
            dfs2(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vll cost(n);
    adj.resize(n);
    adj_rev.resize(n);

    for (auto &i : cost)
        cin >> i;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    used.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            dfs1(i);
    }
    used.assign(n, false);
    reverse(order.begin(), order.end());
    ll min_cost = 0, ways = 1;
    ll md = 1000000007;
    for (auto v : order)
    {
        if (!used[v])
        {
            dfs2(v);
            map<ll, ll> mm;
            ll mn = LLONG_MAX;
            for (auto u : component)
            {
                mm[cost[u]]++;
                mn = min(mn, cost[u]);
            }
            min_cost += mn;
            ways = ((ways * mm[mn]) % md + md) % md;
            component.clear();
        }
    }
    cout << min_cost << " " << ways << nl;
    return 0;
}