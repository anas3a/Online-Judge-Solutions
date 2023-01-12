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

ll n, m;
string a, b;
vector<pair<pll, ll>> vx;
ll dp[5003][5003];

ll f(ll i, ll j)
{
    if (i == n || j == m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + f(i + 1, j + 1);
    }
    else
    {
        ll x = f(i + 1, j);
        ll y = f(i, j + 1);
        ans += max(x, y);
    }
    return dp[i][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    f(0, 0);
    ll cx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cx = max(cx, dp[i][j]);
    }
    cout << cx << endl;
    return 0;
}
