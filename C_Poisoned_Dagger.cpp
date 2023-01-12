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

ll n, h;
vll v;
bool ok(ll m)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            sum += m;
        else
            sum += min(m,v[i + 1] - v[i]);
    }
    return sum >= h;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> h;
        v.clear();
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        ll l = 0, r = 1;
        while (!ok(r))
            r *= 2;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (ok(m))
                r = m;
            else
                l = m;
        }
        cout << r << endl;
    }
    return 0;
}