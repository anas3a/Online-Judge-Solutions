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

    ll n = 1e5;
    vector<bool> fl(n + 3, true);
    vi p;
    fl[0] = fl[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (fl[i])
        {
            p.pb(i);
            for (ll j = i * i; j <= n; j += i)
                fl[j] = false;
        }
    }
    while (true)
    {
        string s;
        getline(cin, s);
        if (sz(s) == 1 && s[0] == '0')
            break;
        stringstream sx(s);
        vll v;
        ll a;
        while (sx >> a)
            v.pb(a);
        ll x = 1;
        for (int i = 0; i < sz(v) - 1; i += 2)
        {
            ll y = v[i], z = v[i + 1], zx = 1;
            while (z != 0)
            {
                zx *= y;
                z--;
            }
            x *= zx;
        }
        x--;
        vpl vx;
        for (int i = sz(p) - 1; i >= 0; i--)
        {
            if (p[i] > x)
                continue;
            int cnt = 0;
            while (x % p[i] == 0)
            {
                x /= p[i];
                cnt++;
            }
            if (cnt)
                vx.pb({p[i], cnt});
        }
        if (x > 1)
            vx.pb({x, 1});
        for (int i = 0; i < sz(vx); i++)
        {
            if (i)
                cout << " ";
            cout << vx[i].ff << " " << vx[i].ss;
        }
        cout << endl;
    }
    return 0;
}
