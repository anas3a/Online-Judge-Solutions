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

    ll n, q, c;
    cin >> n >> q >> c;
    ll v[101][101][c + 1];
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; i++)
    {
        ll x, y, s;
        cin >> x >> y >> s;
        v[x][y][s] += 1;
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                v[i][j][k] += v[i][j - 1][k];
            }
        }
    }

    c++;
    while (q--)
    {
        ll t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        vll vx(c, 0);
        for (int i = x1; i <= x2; i++)
        {
            for (int k = 0; k < c; k++)
            {
                vx[k] += v[i][y2][k] - v[i][y1 - 1][k];
            }
        }
        ll sum = 0;
        for (int i = 0; i < sz(vx); i++)
        {
            sum += ((i + t) % c) * vx[i];
        }
        cout << sum << endl;
    }
    return 0;
}
