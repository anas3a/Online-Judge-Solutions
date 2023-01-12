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

ll md = 100000000;
ll n1, n2, k1, k2;
ll dp[102][102][11][11];
ll f(ll nx1, ll nx2, ll kx1, ll kx2)
{
    if (nx1 > n1)
        return 0;
    if (nx2 > n2)
        return 0;
    if (nx1 + nx2 == n1 + n2)
    {
        if (nx1 == n1 && nx2 == n2)
            return 1;
        else
            return 0;
    }
    if (dp[nx1][nx2][kx1][kx2] != -1)
        return dp[nx1][nx2][kx1][kx2];
    ll a = 0, b = 0;
    if (kx1 < k1)
        a = f(nx1 + 1, nx2, kx1 + 1, 0);
    if (kx2 < k2)
        b = f(nx1, nx2 + 1, 0, kx2 + 1);
    return dp[nx1][nx2][kx1][kx2] = ((a % md) + (b % md)) % md;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << f(0, 0, 0, 0) % md << endl;
    return 0;
}
