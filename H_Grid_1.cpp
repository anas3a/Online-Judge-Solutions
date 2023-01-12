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

ll h, w;
vector<string> v;
ll dp[1003][1003];
ll md = 1e9 + 7;
ll f(int i, int j)
{
    if (i == h - 1 && j == w - 1)
        return 1;
    if (i == h || j == w || v[i][j] == '#')
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = (f(i, j + 1) + f(i + 1, j)) % md;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    v.resize(h);
    memset(dp, -1, sizeof(dp));
    for (auto &i : v)
        cin >> i;
    cout << f(0, 0) % md << endl;
    return 0;
}
