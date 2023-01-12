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

int a[200];
int nx;
int dp[150][150];
int f(int l, int r)
{
    int mx = 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    for (int i = l + 1; i < r; i++)
    {
        int temp = f(l, i) + f(i, r);
        if (l == 0 && r == nx)
            temp += a[i];
        else
            temp += a[l] * a[r];
        mx = max(mx, temp);
    }
    return dp[l][r] = mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a[0] = 1;
        a[n + 1] = 1;
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        nx = n + 1;
        cout << f(0, n + 1) << endl;
    }
    return 0;
}