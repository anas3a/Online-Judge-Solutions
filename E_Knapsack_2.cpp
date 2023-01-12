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

ll n, w;
vpl v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    v.resize(n);
    for (auto &i : v)
        cin >> i.ff >> i.ss;
    ll val = n * 1000;
    vll dp(val + 2, 1e15);
    ll ans = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = val; j >= 0; j--)
        {
            if (dp[j] + v[i].ff <= w && dp[j] + v[i].ff < dp[j + v[i].ss])
                dp[j + v[i].ss] = dp[j] + v[i].ff, ans = max(ans, j + v[i].ss);
        }
    }
    cout << ans << endl;
    return 0;
}
