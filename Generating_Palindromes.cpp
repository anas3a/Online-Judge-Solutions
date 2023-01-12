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
int dp[102][102];
ll f(int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = f(i + 1, j - 1);
    return dp[i][j] = min(f(i + 1, j), f(i, j - 1)) + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cin >> s;
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ++cs << ": ";
        cout << f(0, sz(s) - 1) << endl;
    }
    return 0;
}
