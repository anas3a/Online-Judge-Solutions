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

ll k, x;
bool ok(ll m)
{
    if (m >= 2 * k)
        return false;
    ll sum = 0, a = m;
    if (m <= k)
        sum = (m * (m + 1)) / 2;
    else
    {
        sum = (k * (k + 1)) / 2;
        sum += (k * (k - 1)) / 2;
        ll z = k - (m - k) - 1;
        sum -= (z * (z + 1)) / 2;
        a = k - (m - k);
    }
    return (sum - a) < x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> k >> x;
        ll l = 1, r = (2 * k) + 100;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (ok(m))
                l = m;
            else
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}