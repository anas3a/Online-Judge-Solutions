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

ll n, q;
vll v;
ll dp[202][202][2];
ll f(ll cnt, ll x)
{
    if (x >= n)
        return 0;
    if (dp[]) 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        v.clear();
        v.resize(n);
        for (auto &i : v)
            cin >> i;
        memset(dp, -1, sizeof(dp));
        f(0, 0);
    }
    return 0;
}