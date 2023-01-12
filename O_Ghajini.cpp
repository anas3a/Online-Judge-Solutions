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

    int nx = 2e5;
    vi bin_log(nx + 1, 0);
    for (int i = 2; i < nx; i++)
        bin_log[i] = bin_log[i / 2] + 1;

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++cs << ": ";
        int n, q;
        cin >> n >> q;
        int k = bin_log[n] + 1;
        vvl v(n, vll(k, 0)), vx(n, vll(k, 0));
        for (int i = 0; i < n; i++)
            cin >> v[i][0], vx[i][0] = v[i][0];
        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                v[i][j] = min(v[i][j - 1], v[i + (1 << (j - 1))][j - 1]);
                vx[i][j] = max(vx[i][j - 1], vx[i + (1 << (j - 1))][j - 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= n - q; i++)
        {
            int a, b;
            a = i, b = i + q - 1;
            int c = bin_log[b - a + 1];
            int minx = min(v[a][c], v[b - (1 << c) + 1][c]);
            int maxx = max(vx[a][c], vx[b - (1 << c) + 1][c]);
            ans = max(ans, maxx - minx);
        }
        cout << ans << '\n';
    }
    return 0;
}