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

ll n;
vll w, sign;
vvl g;
vector<bool> vis;
void dfs(int i, int sign_val)
{
    sign[i] = sign_val;
    sign_val = 1 - sign_val;
    vis[i] = true;
    for (auto &v : g[i])
    {
        if (!vis[v])
            dfs(v, sign_val);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll t, cs = 0;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        w.clear();
        w.resize(n, 0);
        sign.clear();
        sign.resize(n);
        g.clear();
        g.resize(n);
        vis.clear();
        vis.resize(n, false);
        for (auto &i : w)
            scanf("%lld", &i);
        for (int i = 0; i < n - 1; i++)
        {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            u--;
            v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0, 0);
        ll mx = LLONG_MIN, ans = 1, sumpos = 0, sumneg = 0, szpos = 0, szneg = 0;
        for (int i = 0; i < n; i++)
        {
            if (!sign[i])
            {
                sumpos += w[i];
                szpos++;
            }
            else 
            {
                sumneg += w[i];
                szneg++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ll z=0;
            if (!sign[i])
            {
                z = sumneg - (w[i] * szneg);
                z += (w[i] * szpos) - (sumpos);
            }
            else 
            {
                z = (w[i] * szneg) - (sumneg);
                z += sumpos - (w[i] * szpos);
            }
            if (z > mx)
            {
                mx = z;
                ans = i;
            }
        }
        printf("Case %lld: %lld\n",++cs, ans + 1);
    }
    return 0;
}