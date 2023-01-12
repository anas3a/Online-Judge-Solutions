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

int n, m, k, x1, yy1, x2, y2;
vector<string> g;
vvi lev;
bool vis[1003][1003][4];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
bool valid(int nx, int ny, int i)
{
    return (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && !vis[nx][ny][i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    g.resize(n);
    lev.resize(n, vi(m, INT_MAX));
    for (auto &i : g)
        cin >> i;
    cin >> x1 >> yy1 >> x2 >> y2;
    x1--, yy1--, x2--, y2--;

    queue<pii> q;
    q.push({x1, yy1});
    lev[x1][yy1] = 0;
    while (!q.empty())
    {
        int tx = q.front().ff, ty = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tx + dr[i], ny = ty + dc[i];
            for (int j = 0; j < k; j++)
            {
                if (!valid(nx, ny, i))
                    break;
                q.push({nx, ny});
                vis[nx][ny][i] = true;
                if (lev[nx][ny] > lev[tx][ty] + 1)
                    lev[nx][ny] = lev[tx][ty] + 1;
                nx += dr[i];
                ny += dc[i];
            }
        }
    }
    if (lev[x2][y2] == INT_MAX)
        cout << -1 << endl;
    else
        cout << lev[x2][y2] << endl;
    return 0;
}
