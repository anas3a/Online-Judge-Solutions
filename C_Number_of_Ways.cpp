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

    ll n;
    cin >> n;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    ll sum = accumulate(all(v), 0LL);
    if (sum % 3)
        cout << 0 << endl;
    else
    {
        ll z = sum / 3;
        vll pre(n, 0), suf(n, 0);
        pre[0] = v[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + v[i];
        suf[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + v[i];
        vll vx;
        for (int i = 1; i < n - 1; i++)
        {
            if (z * 2 == pre[i] && suf[i + 1] == z)
                vx.pb(i);
        }
        ll ans = 0, sumx = 0;
        for (int i = 0; i < n - 2; i++)
        {
            sumx += v[i];
            if (sumx == z)
            {
                ll ind = upper_bound(all(vx), i) - vx.begin();
                ans += sz(vx) - ind;
            }
        }
        cout << ans << endl;
    }
    return 0;
}