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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

ll n, s;
vpl v;
ll dp[102][3][10004], ansx[102][3][10004];
string ans;
void f1(ll ind, ll pos, ll sx)
{
    if (ind == n)
        return;
    if (ansx[ind][pos][sx] == 1)
    {
        ans += 'H';
        f1(ind + 1, 1, sx - v[ind].ff);
    }
    else
    {
        ans += 'T';
        f1(ind + 1, 2, sx - v[ind].ss);
    }
    return;
}
bool f(ll ind, ll pos, ll sx)
{
    if (sx < 0)
        return false;
    if (ind == n)
        return (sx == 0);
    if (dp[ind][pos][sx] != -1)
        return dp[ind][pos][sx];
    bool xx = f(ind + 1, 1, sx - v[ind].ff);
    bool yy = f(ind + 1, 2, sx - v[ind].ss);
    if (xx)
    {
        ansx[ind][pos][sx] = 1;
    }
    else if (yy)
    {
        ansx[ind][pos][sx] = 2;
    }
    return dp[ind][pos][sx] = xx || yy;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (auto &i : v)
        cin >> i.ff >> i.ss;
    bool x = f(0, 0, s);
    if (x)
    {
        cout << "Yes" << nl;
        f1(0, 0, s);
        cout << ans << nl;
    }
    else
        cout << "No" << nl;
    return 0;
}