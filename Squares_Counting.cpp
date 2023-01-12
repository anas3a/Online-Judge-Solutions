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
        vector<string> vs(n);
        for (auto &i : vs)
            cin >> i;
        vvi prow(n + 1, vi(n + 1, 0));
        vvi pcol(n + 1, vi(n + 1, 0));
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prow[i][j] = prow[i][j - 1] + (vs[i - 1][j - 1] - '0');
                ans += vs[i - 1][j - 1] - '0';
            }
        }
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
                pcol[i][j] = pcol[i - 1][j] + (vs[i - 1][j - 1] - '0');
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                for (int k = 2; k <= n; k++)
                {
                    if (i + k - 1 > n || j + k - 1 > n)
                        break;
                    if (prow[i][j + k - 1] - prow[i][j - 1] < k)
                        continue;
                    if (prow[i + k - 1][j + k - 1] - prow[i + k - 1][j - 1] < k)
                        continue;
                    if (pcol[i + k - 1][j] - pcol[i - 1][j] < k)
                        continue;
                    if (pcol[i + k - 1][j + k - 1] - pcol[i - 1][j + k - 1] < k)
                        continue;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}