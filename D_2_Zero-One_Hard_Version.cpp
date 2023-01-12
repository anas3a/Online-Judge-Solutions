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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vll vx;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                vx.pb(i);
        }
        if (sz(vx) % 2)
            cout << -1 << nl;
        else
        {
            if (x >= y)
            {
                if (sz(vx) == 2 && vx[0] + 1 == vx[1])
                    cout << min(2 * y, x) << nl;
                else
                    cout << (sz(vx) / 2) * y << nl;
            }
            else
            {
                ll ans = 0;
                vll st;
                for (int i = 0; i < n; i++)
                {
                    if (vx[i] + 1 == vx[i + 1])
                    {
                        ans += x;
                        i++;
                    }
                    else
                    {
                        st.pb(vx[i]);
                    }
                }
                while (true)
                {
                    bool flag = false;
                    for (int i = 0; i < sz(st); i++)
                    {
                        auto z = lower_bound(all(st), st[i] + 2);
                        if (z != st.end())
                        {
                            ans += (x + x);
                            vll tmp;
                            ll zx = z - st.begin();
                            for (int j = 0; j < sz(st); j++)
                            {
                                if (j == i || j == zx)
                                    continue;
                                tmp.pb(st[j]);
                            }
                            flag = true;
                            st = tmp;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
                ans += ((sz(st)) / 2) * (x + y);
                cout << ans << nl;
            }
        }
    }
    return 0;
}