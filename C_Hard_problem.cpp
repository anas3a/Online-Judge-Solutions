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

ll n;
vll c;
vector<string> v;
bool fx = false;
vector <vll > dp;

ll f(int i, string s, int l)
{
    if (i == n)
    {
        fx = true;
        return 0;
    }
    if (dp[i][l] != -1)
        return dp[i][l];
    ll a = 1e18, b = 1e18;
    string sx = v[i];
    ll fy = true;
    reverse(all(sx));
    if (v[i] >= s)
        a = f(i + 1, v[i], 1), fy = false;
    if (sx >= s)
        b = c[i] + f(i + 1, sx, 2), fy = false;
    if (fy)
        return 1e16;
    return dp[i][l] = min(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    c.resize(n);
    v.resize(n);
    dp.resize(n + 1, vll(3, - 1));
    for (auto &i : c)
        cin >> i;
    for (auto &i : v)
        cin >> i;
    ll x = f(0, "1", 1);
    if (fx)
        cout << x << endl;
    else
        cout << -1 << endl;
    return 0;
}
