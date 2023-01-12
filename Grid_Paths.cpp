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

ll n, md = 1e9 + 7;
vector<string> v;
ll dp[1003][1003];
ll f(int i, int j)
{
    if (i == n || j == n || v[i][j] == '*')
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = (f(i + 1, j) + f(i, j + 1)) % md;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << endl;
    return 0;
}
