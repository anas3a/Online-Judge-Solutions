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

    ll n, ans = 0;
    cin >> n;
    vvi v(1002, vi(1002, 0));
    vvi vx = v;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x][y] = 1;
    }
    vx[0][0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        vx[i][0] = vx[i][i] = 1;
        for (int j = 1; j <= 1000; j++)
            vx[i][j] = vx[i - 1][j - 1] + vx[i - 1][j];
    }
    for (int i = 1; i <= 1000; i++)
    {
        ll x = i, y = 1, cnt = 0;
        while (x != 0)
        {
            if (v[y][x] == 1)
                cnt++;
            y++;
            x--;
        }
        if (cnt > 1)
            ans += vx[cnt][2];
    }
    for (int i = 2; i <= 1000; i++)
    {
        ll x = i, y = 1000, cnt = 0;
        while (x != 1001)
        {
            if (v[x][y] == 1)
                cnt++;
            y--;
            x++;
        }
        if (cnt > 1)
            ans += vx[cnt][2];
    }
    for (int i = 1000; i >= 1; i--)
    {
        ll x = i, y = 1, cnt = 0;
        while (x != 1001)
        {
            if (v[y][x] == 1)
                cnt++;
            y++;
            x++;
        }
        if (cnt > 1)
            ans += vx[cnt][2];
    }
    for (int i = 2; i <= 1000; i++)
    {
        ll x = i, y = 1, cnt = 0;
        while (x != 1001)
        {
            if (v[x][y] == 1)
                cnt++;
            y++;
            x++;
        }
        if (cnt > 1)
            ans += vx[cnt][2];
    }
    cout << ans << endl;
    return 0;
}
