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
vll v1, v2, v1x, v2x;

bool f(ll x)
{
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] < x)
        {
            ll z = lower_bound(all(v2x), x - v1[i]) - v2x.begin();
            s += z;
        }
    }
    return s < k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    v1.resize(n);
    v2.resize(n);
    for (auto &i : v1)
        cin >> i;
    for (auto &i : v2)
        cin >> i;
    v1x = v1;
    v2x = v2;
    sort(all(v1x));
    sort(all(v2x));
    ll l = -1, r = 2e10;
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
