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

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll n, w;
        cin >> n >> w;
        vll v(n);
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a >> v[i];
        }
        sort(all(v));
        ll ans = 0, pos = 0, val = v[0];
        while (true)
        {
            ans++;
            val += (w + 1);
            pos = lower_bound(all(v), val) - v.begin();
            if (pos == n)
                break;
            val = v[pos];
        }
        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0;
}