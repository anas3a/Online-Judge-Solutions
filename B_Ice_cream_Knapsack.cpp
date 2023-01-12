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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("icecream.in", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vpl c(n), h(n);
        for (int i = 0; i < n; i++)
            cin >> c[i].ff, c[i].ss = i;
        for (int i = 0; i < n; i++)
            cin >> h[i].ff, h[i].ss = i;
        sort(all(c));
        vpl v;
        ll mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < k)
                v.pb(c[i]);
            if (i == k - 1)
                mx = c[i].ff;
            if (i >= k && c[i].ff <= mx)
                v.pb(c[i]);
        }
        vll vx;
        for (int i = 0; i < sz(v); i++)
        {
            vx.pb(h[v[i].ss].ff);
        }
        sort(rall(vx));
        ll ans = 0;
        for (int i = 0; i < k; i++)
            ans += vx[i];
        cout << mx << " " << ans << endl;
    }
    return 0;
}