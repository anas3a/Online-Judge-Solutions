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
vector<char> v(30);
ll dp[100005][30];
ll f(ll i, char c)
{
    if (i == sz(s))
        return 0;
    ll &ans = dp[i][c - 'a'];
    if (ans != -1)
        return ans;
    ll a = INT_MAX, b = INT_MAX;
    a = 1 + f(i + 1, c);
    if (v[c - 'a'] != s[i])
        b = f(i + 1, s[i]);
    return ans = min(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int k;
    cin >> k;
    while (k--)
    {
        string t;
        cin >> t;
        v[t[0] - 'a'] = t[1];
        v[t[1] - 'a'] = t[0];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, 'z' + 1) << endl;
    return 0;
}