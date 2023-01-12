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

ll md = 1e9 + 7;
long long binpow(long long a, long long b)
{
    a %= md;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % md;
        a = a * a % md;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vll v;
    ll x = 1, cnt = 1;
    while (x <= 2e9 + 7)
    {
        v.pb(x);
        x += cnt;
        cnt++;
    }
    ll nx = 1e5;
    vll fact(nx + 5), inv(nx + 5);
    fact[0] = 1;
    for (ll i = 1; i <= nx; i++)
        fact[i] = fact[i - 1] * i % md;

    ll t;
    cin >> t;
    while (t--)
    {
        ll s, e;
        cin >> s >> e;
        ll ind1 = lower_bound(all(v), s) - v.begin();
        ll ind2 = lower_bound(all(v), e) - v.begin();
        if (v[ind1] != s)
            ind1--;
        if (v[ind2] != e)
            ind2--;
        if (s == e)
            cout << 1 << endl;
        else if (ind2 <= ind1)
            cout << 0 << endl;
        else
        {
            ll len = ind2 - ind1;
            ll sum1 = (len * (ind1 + ind2 + 1)) / 2;
            ll sum2 = (len * (ind1 + ind2 + 3)) / 2;
            ll low = sum1 + s;
            ll high = sum2 + s;
            if (low > e || high < e)
                cout << 0 << endl;
            else if (low == e || high == e)
                cout << 1 << endl;
            else
            {
                ll k = e - low;
                if (len < k)
                    cout << 0 << endl;
                else if (k == 0)
                    cout << 1 << endl;
                else
                {
                    ll ans = (fact[len] * binpow(fact[k], md - 2) % md * binpow(fact[len - k], md - 2) %md) % md;
                    cout << ans << endl;
                }
            }
        }
    }
    return 0;
}