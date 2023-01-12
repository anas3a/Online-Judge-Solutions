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

vll v;
ll n, c;
bool f(ll m)
{
    ll cnt = 1;
    ll pos = v[0];
    for (int i = 1; i < sz(v); i++)
    {
        if (v[i] - pos >= m)
        {
            cnt++;
            pos = v[i];
        }
    }
    return cnt >= c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        v.clear();
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        sort(all(v));
        ll l = 0, r = 1;
        while (f(r))
            r *= 2;
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
