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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, r1, c1, r2, c2;
    cin >> n;
    vll v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cin >> r1 >> c1 >> r2 >> c2;
    queue<pll> q;
    q.push({r1, c1});
    map<pll, int> m;
    m[{r1, c1}] = 1;
    ll mx = 1e9;
    while (!q.empty())
    {
        ll x = q.front().ff, y = q.front().ss;
        q.pop();
        if (x == r2)
            mx = min(mx, abs(c2 - y) + m[{x, y}] - 1);
        vi vx = {1, -1, 0, 0}, vy = {0, 0, 1, -1};
        for (int i = 0; i < 2; i++)
        {
            ll xx = x + vx[i], yy = y + vy[i];
            if (xx == 0 || yy == 0 || xx > n || yy > v[x] + 1)
                continue;
            if (yy > v[xx] + 1)
                yy = v[xx] + 1;
            if (m[{xx, yy}] != 0)
                continue;
            q.push({xx, yy});
            m[{xx, yy}] = m[{x, y}] + 1;
        }
    }
    cout << mx << endl;
    return 0;
}
