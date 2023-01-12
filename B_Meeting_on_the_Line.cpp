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

ll n;
vll v, vt;
bool f(double t)
{
    double mx = -1e18, mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (t < vt[i])
            return false;
        mx = max(mx, v[i] - max(t - vt[i], 0.0));
        mn = min(mn, v[i] + max(t - vt[i], 0.0));
    }
    return (mn - mx) > 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        v.clear();
        vt.clear();
        v.resize(n);
        vt.resize(n);
        for (auto &i : v)
            cin >> i;
        for (auto &i : vt)
            cin >> i;
        vpl vx(n);
        for (int i = 0; i < n; i++)
        {
            vx[i].ff = v[i];
            vx[i].ss = vt[i];
        }
        sort(all(vx));
        double l = 0, r = 1;
        while (!f(r))
            r *= 2;
        for (int i = 0; i < 100; i++)
        {
            double m = (l + r) / 2.0;
            if (f(m))
                r = m;
            else
                l = m;
        }
        set<double> st1, st2;
        for (int i = 0; i < sz(vx); i++)
        {
            st1.insert((vx[i].ff) - (r - vx[i].ss));
            st2.insert((vx[i].ff) + (r - vx[i].ss));
        }
        for (auto &i : st1)
        {
            auto it = st2.lower_bound(i);
            if (abs(*it - i) < 1e-6)
            {
                cout << fixed << setprecision(8) << i << nl;
                break;
            }
        }
    }
    return 0;
}