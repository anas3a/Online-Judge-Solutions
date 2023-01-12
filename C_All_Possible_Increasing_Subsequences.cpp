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
ll n;
ll md = 1e9 + 7;
map<pii, ll> dp;

ll f(int i, int x)
{
    if (i == n)
        return 1;
    if (dp[{i, x}])
        return dp[{i, x}];
    ll a = 0, b = 0;
    if (x == -1 || v[x] < v[i])
        a = f(i + 1, i);
    b = f(i + 1, x);
    return dp[{i, x}] = (a + b) % md;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        v.clear();
        v.resize(n);
        dp.clear();
        for (auto &i : v)
            cin >> i;
        cout << "Case " << ++cs << ": ";
        cout << f(0, -1) - 1 << endl;
    }
    return 0;
}