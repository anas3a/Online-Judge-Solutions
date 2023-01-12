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

    ll q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        ll tx = 0, mn = m, mx = m;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            ll t, l, r;
            cin >> t >> l >> r;
            ll tz = t - tx;
            if (l > mn)
                mn = min(l, mn + tz);
            else
                mn -= tz;
            if (r < mx)
                mx = max(r, mx - tz);
            else
                mx += tz;
            if (mx > r && mn <= r)
                mx = r;
            if (mn < l && mx >= l)
                mn = l;
            if ((mx < l) || (mn > r))
                flag = false;
            tx = t;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
