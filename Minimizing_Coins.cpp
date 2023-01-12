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

ll n, x;
vll v;
ll dp[1000006];
ll f(ll w)
{
    if (w == 0)
        return 0;
    if (w < 0)
        return INT_MAX;
    if (dp[w] != -1)
        return dp[w];
    ll ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, 1 + f(w - v[i]));
    return dp[w] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    memset(dp, -1, sizeof(dp));
    ll ans = f(x);
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}
