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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n + 1);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vll dp(n + 1);
        vll chck(1e6 + 5, -1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1]) % md;
            if (chck[v[i - 1]] != -1)
                dp[i] = (dp[i] - dp[chck[v[i - 1]]]) % md;
            chck[v[i - 1]] = i - 1;
        }
        cout << (dp[n] - 1) % md << endl;
    }
    return 0;
}