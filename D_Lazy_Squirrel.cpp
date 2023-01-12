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

string s, x;
int n, cnt;
vvi g;
vector<bool> vis;
ll base = 49308647, md = 1000002043;
void dfs(int u, ll front_hash, ll back_hash, ll base_p)
{
    front_hash = (front_hash + ((s[u] * base_p) % md)) % md;
    back_hash = ((back_hash * base) % md + s[u]) % md;
    if (front_hash == back_hash)
        cnt++;
    vis[u] = true;
    base_p *= base;
    base_p %= md;
    for (auto &i : g[u])
    {
        if (!vis[i])
            dfs(i, front_hash, back_hash, base_p);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        g.clear();
        g.resize(n);
        vis.clear();
        vis.resize(n, false);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        cnt = 0;
        dfs(0, 0, 0, 1);
        cout << "Case " << ++cs << ": ";
        cout << cnt << "/" << n << nl;
    }
    return 0;
}