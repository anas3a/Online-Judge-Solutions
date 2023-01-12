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
vll v;
bool f(ll x)
{
    ll sum = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > x)
            return false;
        if (sum + v[i] > x)
        {
            z++;
            sum = 0;
        }
        sum += v[i];
    }
    if (sum)
        z++;
    return z <= k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    ll l = 0, r = 1;
    while (!f(r))
        r *= 2;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (f(m))
            r = m;
        else
            l = m;
    }
    cout << r << endl;
    return 0;
}
