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

ll n, m, l, r;
vvi v;
vi vx;
bool f(ll x)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll z = 0;
        ll a = x / ((v[i][0] * v[i][2]) + v[i][1]);
        z += a * v[i][2];
        int b = x % ((v[i][0] * v[i][2]) + v[i][1]);
        z += min(b / v[i][0], v[i][2]);
        sum += z;
        vx[i] = z;
    }
    return sum >= m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    v.resize(n, vi(3));
    for (int i = 0; i < sz(v); i++)
        cin >> v[i][0] >> v[i][2] >> v[i][1];
    vx.resize(n, 0);
    if (m == 0)
    {
        cout << 0 << endl;
        for (auto &i : vx)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    ll l = 0, r = 1e9;
    while (l + 1 < r)
    {
        ll xy = (l + r) / 2;
        if (f(xy))
            r = xy;
        else
            l = xy;
    }
    cout << r << endl;
    f(r);
    for (int i = 0; i < n; i++)
    {
        if (vx[i] <= m)
        {
            cout << vx[i] << " ";
            m -= vx[i];
        }
        else
        {
            cout << m << " ";
            m = 0;
        }
    }
    cout << endl;
    return 0;
}
