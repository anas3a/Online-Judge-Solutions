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
ll n;
vll v = {1, 2, 3, 4, 5, 6};
ll dp[1000006];

ll f(ll w)
{
    if (w < 0)
        return 0;
    if (w == 0)
        return 1;
    if (dp[w] != -1)
        return dp[w];
    ll cnt = 0;
    for (int i = 0; i < sz(v); i++)
        cnt += f(w - v[i]) % md;
    return dp[w] = cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n) % md << endl;
    return 0;
}
