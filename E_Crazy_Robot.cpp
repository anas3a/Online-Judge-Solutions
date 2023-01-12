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
        ll n, m;
        cin >> n >> m;
        vector<string> g(n);
        pll loc;
        for (int i = 0; i < n; i++)
        {
            cin >> g[i];
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] == 'L')
                    loc = {i, j};
            }
        }

        queue<pll> q;

        q.push({loc});
        int fx[] = {+1, -1, +0, +0};
        int fy[] = {+0, +0, +1, -1};
        for (int i = 0; i < 4; i++)
        {
            ll xx = loc.ff + fx[i];
            ll yy = loc.ss + fy[i];
            ll cnt = 0;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == '.')
            {
                ll cx = -1, cy = -1;
                for (int j = 0; j < 4; j++)
                {
                    ll xz = xx + fx[j];
                    ll yz = yy + fy[j];
                    if (xz >= 0 && xz < n && yz >= 0 && yz < m && g[xz][yz] == '.')
                    {
                        cx = xz;
                        cy = yz;
                        cnt++;
                    }
                }
            }
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == '.' && cnt <= 1)
                q.push({xx, yy});
        }
        while (!q.empty())
        {
            ll x = q.front().ff, y = q.front().ss;
            q.pop();
            ll cnt = 0;
            ll cx = -1, cy = -1;
            for (int i = 0; i < 4; i++)
            {
                ll xx = x + fx[i];
                ll yy = y + fy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == '.')
                {
                    cx = xx;
                    cy = yy;
                    cnt++;
                }
            }
            if (cnt <= 1 && cx >= 0 && cx < n && cy >= 0 && cy < m && g[cx][cy] == '.')
            {
                q.push({cx, cy});
            }
            if (cnt <= 1)
                g[x][y] = '+';
        }
        g[loc.ff][loc.ss] = 'L';
        for (auto &i : g)
            cout << i << '\n';
    }
    return 0;
}