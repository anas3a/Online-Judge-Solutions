#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

    ll n, ans = 0;
    cin >> n;
    while (n--)
    {
        ll p;
        cin >> p;
        vpl v;
        for (int i = 0; i < p; i++)
        {
            ll x, y;
            cin >> x >> y;
            v.pb(mp(x, y));
        }
        v.pb(mp(v[0].ff, v[0].ss));
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < p; i++)
        {
            sum1 += (v[i].ff * v[i + 1].ss);
            sum2 += (v[i].ss * v[i + 1].ff);
        }
        ans += abs(sum1 - sum2);
    }
    cout << ans / 2 << endl;
    return 0;
}
