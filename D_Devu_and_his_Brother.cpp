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

ll n, m;
vll a, b;
ll f(ll m)
{
    ll sum = 0;
    for (auto &i : a)
    {
        if (i < m)
            sum += m - i;
    }
    for (auto &i : b)
    {
        if (i > m)
            sum += i - m;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    ll l = 1, r = 1e9;
    while (l + 2 < r)
    {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        if (f(m1) < f(m2))
            r = m2;
        else
            l = m1;
    }
    ll ans = LLONG_MAX;
    for (int i = l; i <= r; i++)
    {
        ans = min(ans, f(i));
    }
    cout << ans << nl;
    return 0;
}