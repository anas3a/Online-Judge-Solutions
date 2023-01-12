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
vpl v;
vll vx;

bool f(ll m)
{
    if (2 * m > n)
        return false;
    int j = 0;
    vll vy(m, 0);
    for (int i = 0; i < m; i++)
    {
        vy[i] += vx[j++];
    }
    for (int i = m - 1; i >= 0; i--)
    {
        vy[i] += vx[j++];
    }
    for (int i = 0; i < m; i++)
    {
        if (vy[i] < 0)
            return false;
    }
    return true;
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
        v.resize(n);
        vx.clear();
        for (auto &i : v)
            cin >> i.ff;
        for (auto &i : v)
            cin >> i.ss, vx.pb(i.ss - i.ff);
        sort(rall(vx));
        ll l = 0, r = n;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (f(m))
                l = m;
            else
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}