#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

vvi graph;
vector<bool> visited;
vi ans;

void dfs(int u)
{
    visited[u] = true;
    for (auto v : graph[u])
    {
        if (!visited[v])
            dfs(v);
    }
    ans.pb(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i <= k; i++)
    {
        ll a;
        cin >> a;
        while (a--)
        {
            ll x;
            cin >> x;
            graph[i].pb(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    vi p(n + 1, 0);
    for (int i = sz(ans) - 2; i >= 0; i--)
    {
        p[ans[i]] = ans[i + 1];
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << endl;
    return 0;
}
