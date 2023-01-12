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
        ll m;
        cin >> m;
        vi v(m + 1);
        for (int i = 1; i <= m; i++)
            cin >> v[i];
        ll ans = 0, x = 1;
        bool flag = true;
        while (true)
        {
            ll cnt = 0, cntx = 1;
            vi vx, vy;
            for (int i = 1; i <= m; i++)
            {
                if (sz(vx) == x)
                    vy.pb(v[i]);
                else
                    vx.pb(v[i]);
                if (sz(vx) == x && sz(vy) == x)
                {
                    vi vxx = vx;
                    for (auto &i : vy)
                        vxx.pb(i);
                    vi vyy = vy;
                    for (auto &i : vx)
                        vyy.pb(i);
                    vi vxy = vxx;
                    sort(all(vxy));
                    if (vxy == vxx || vxy == vyy)
                    {
                        if (vxy == vyy)
                            ans++;
                        for (int j = cntx, k = 0; k < sz(vxy); j++, k++)
                            v[j] = vxy[k];
                        cntx = i + 1;
                    }
                    else
                    {
                        ans = -1;
                        flag = false;
                        break;
                    }
                    vx.clear();
                    vy.clear();
                }
            }
            if (!flag)
                break;
            x *= 2;
            if (x > m)
                break;
        }
        cout << ans << nl;
    }
    return 0;
}