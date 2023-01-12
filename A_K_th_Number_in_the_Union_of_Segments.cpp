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

ll n, k;
vpl v;

bool f(ll m)
{
    ll sum = 0;
    for (auto &i : v)
    {
        if (i.ff < m)
            sum += min(m - i.ff, i.ss - i.ff + 1);
    }
    return sum <= k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    v.resize(n);
    for (auto &i : v)
        cin >> i.ff >> i.ss;
    ll l = -3e9, r = 3e9;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (f(m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}
