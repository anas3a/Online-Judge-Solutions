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

string s;
ll md = 1e9 + 7, n;
ll dp[100005];
ll f(ll i)
{
    if (i == n)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    ll a = 0, b = 0;
    if ((s[i] == 'n' || s[i] == 'u') && i < n - 1 && s[i] == s[i + 1])
        a = f(i + 2);
    b = f(i + 1);
    return dp[i] = ((a % md) + (b % md)) % md;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = sz(s);
    for (auto &i : s)
    {
        if (i == 'm' || i == 'w')
        {
            cout << 0 << endl;
            return 0;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0) << endl;
    return 0;
}
