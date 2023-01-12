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

    ll x, y, a, b;
    cin >> x >> y;
    ll n;
    cin >> n;
    ll sum = 0;
    vll v;
    vll vx(x + 3, -1), vy(x + 3, 1e6);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vx[a] = max(vx[a], b);
        vy[a] = min(vy[a], b);
    }
    for (int i = 0; i <= x; i++)
    {
        if (vx[i] != -1)
            v.pb(vx[i]);
        if (vy[i] != 1e6)
            v.pb(vy[i]);
    }
    sort(all(v));
    ll m = (sz(v) + 1) / 2;
    ll p = v[m - 1];
    sum += x - 1;
    for (int i = 0; i < sz(vx); i++)
    {
        if (vx[i] != -1 && vx[i] > p)
            sum += abs(p - vx[i]) * 2;
        if (vy[i] != 1e6 && vy[i] < p)
            sum += abs(p - vy[i]) * 2;
    }
    cout << sum << endl;
    return 0;
}
