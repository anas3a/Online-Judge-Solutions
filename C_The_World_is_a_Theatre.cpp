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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, t, ans = 0;
    cin >> n >> m >> t;
    ll x = max(n, m);
    ll v[x + 1][x + 1];
    memset(v, 0, sizeof(v));
    v[0][0] = 1;
    for (int i = 1; i <= x; i++)
    {
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j <= x; j++)
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
    }
    ll a = min(t - 1, n), b = t - a;
    for (int i = 0;; i++)
    {
        if (a < 4 || b > m)
            break;
        ans += v[n][a] * v[m][b];
        a--;
        b++;
    }
    cout << ans << endl;
    return 0;
}
