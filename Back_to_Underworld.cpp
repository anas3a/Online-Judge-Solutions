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

vvl g;
vi color;
void dfs(ll u)
{
    ll colorchild = 1 - color[u];
    for (auto &i : g[u])
    {
        if (color[i] == -1)
        {
            color[i] = colorchild;
            dfs(i);
        }
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
        ll n = 20000, nx;
        scanf("%lld", &nx);
        g.clear();
        g.resize(n + 1);
        color.clear();
        color.resize(n + 1, -1);
        set<ll> st;
        for (int i = 0; i < nx; i++)
        {
            ll u, v;
            scanf("%lld %lld", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
            st.insert(u);
            st.insert(v);
        }
        for (auto &i : st)
        {
            if (color[i] == -1)
                color[i] = 0, dfs(i);
        }
        ll c0 = 0, c1 = 0;
        for (auto &i : st)
        {
            if (color[i] == 0)
                c0++;
            else
                c1++;
        }
        printf("Case %lld: %lld\n", ++cs, max(c0, c1));
    }
    return 0;
}