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

int n1, n2;
string x, y;
int dp[1002][1002];
ll f(int i, int j)
{
    if (i == n1 || j == n2)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (x[i] == y[j])
        ans = 1 + f(i + 1, j + 1);
    else
    {
        int a = f(i + 1, j);
        int b = f(i, j + 1);
        ans = max(a, b);
    }
    return dp[i][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c = 0;
    cin >> n;
    while (n--)
    {
        cin >> n1 >> n2 >> x >> y;
        memset(dp, -1, sizeof(dp));
        ll ans = f(0, 0);
        cout << "Case " << ++c << ": " << n1 + n2 - ans << endl;
    }
    return 0;
}
