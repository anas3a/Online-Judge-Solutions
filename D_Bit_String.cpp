// D. Bit String


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
ll dp[100005][2];

ll f(ll i, ll x)
{
    if (i == sz(s) - 1)
        return x;

    if (dp[i][x] != -1)
        return dp[i][x];

    ll a = 1, b = 1;
    if (s[i] == '0' && !x)
    {
        a += f(i + 1, x);
        b = a;
    }
    else if (s[i] == '1' && x)
    {
        a += f(i + 1, x);
        b = a;
    }
    else
    {
        a += 1 + f(i + 1, x);
        b += 1 + f(i + 1, 1 - x);
    }
    return dp[i][x] = min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        reverse(all(s));
        memset(dp, -1, sizeof(dp));
        cout << f(0, 0) << endl;
    }
    return 0;
}