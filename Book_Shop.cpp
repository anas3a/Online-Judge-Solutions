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

ll n, x, mx = 1e5;
vll h, s;
ll dp[1003][100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    h.resize(n), s.resize(n);
    for (auto &i : h)
        cin >> i;
    for (auto &i : s)
        cin >> i;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= mx; j++)
        {
            if (j + h[i] <= x)
                dp[i + 1][j + h[i]] = max(dp[i + 1][j + h[i]], dp[i][j] + s[i]);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
