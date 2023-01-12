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

string s, t, ans;
ll dp[3003][3003];
pll sol[3003][3003];
ll f(ll i, ll j)
{
    if (i == sz(s) || j == sz(t))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll a = 0;
    if (s[i] == t[j])
    {
        a = 1 + f(i + 1, j + 1);
        sol[i][j] = {i + 1, j + 1};
    }
    else
    {
        ll x = f(i + 1, j);
        ll y = f(i, j + 1);
        if (x >= y)
        {
            a = x;
            sol[i][j] = {i + 1, j};
        }
        else
        {
            a = y;
            sol[i][j] = {i, j + 1};
        }
    }
    return dp[i][j] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    pll in = {0, 0}, end = {-1, -1};
    ll cnt = f(0, 0);
    while (true)
    {
        if (s[in.ff] == t[in.ss])
            ans += s[in.ff];
        in = sol[in.ff][in.ss];
        if (cnt == sz(ans))
            break;
    }
    cout << ans << endl;
    cout << ~(-1) << endl;
    return 0;
}
