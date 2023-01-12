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
vll vx, vv;
bool f(double t)
{
    double mx = -1e18, mn = 1e18;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, vx[i] - (t * vv[i]));
        mn = min(mn, vx[i] + (t * vv[i]));
    }
    return (mn - mx) > 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vx.resize(n);
    vv.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vx[i];
        cin >> vv[i];
    }
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
    cout << fixed << setprecision(20) << r << endl;
    return 0;
}
