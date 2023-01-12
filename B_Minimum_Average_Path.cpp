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

ll n, m;
vector<vpl> v;
ll ans = 0;
vi ansv;

bool bfs(double z)
{
    queue<ll> q;
    vector<bool> vis(n + 1, false);
    vector<int> lev(n + 1, 0), p(n + 1), sum(n + 1, 0);
    q.push(1);
    vis[1] = true;
    p[1] = -1;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (auto &u : v[x])
        {
            if (!vis[u.ff])
            {
                q.push(u.ff);
                vis[u.ff] = true;
                lev[u.ff] = lev[x] + 1;
                p[u.ff] = x;
                sum[u.ff] += sum[x] + u.ss;
            }
        }
    }
    double aa = sum[n] / (double)lev[n];
    if (aa <= z)
    {
        ansv.clear();
        ans = lev[n];
        for (int i = n; i != -1; i = p[i])
            ansv.pb(i);
        reverse(all(ansv));
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n + 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
    }
    ll l = -1, r = 500;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (bfs(m))
            l = m;
        else
            r = m;
    }
    bfs(l);
    cout << ans << endl;
    for (auto &i : ansv)
        cout << i << " ";
    cout << endl;
    return 0;
}
