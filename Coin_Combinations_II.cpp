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

ll md = 1e9 + 7;
ll n, x;
int v[102];
int dp[1000006];

// ll f(int i, int w)
// {
//     if (w < 0)
//         return 0;
//     if (i == n)
//     {
//         if (w == 0)
//             return 1;
//         return 0;
//     }
//     if (dp[i][w] != -1)
//         return dp[i][w];
//     ll cnt = f(i, w - v[i]) + f(i + 1, w);
//     if (cnt >= md)
//         cnt -= md;
//     return dp[i][w] = cnt;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> v[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - v[i] >= 0)
                dp[j] += dp[j - v[i]];
            if (dp[j] >= md)
                dp[j] -= md;
        }
    }
    cout << dp[x] << endl;
    return 0;
}
