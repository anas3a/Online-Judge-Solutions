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

int n, m;
vvi lev;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
bool valid(int nx, int ny, int lv)
{
    return (nx >= 1 && nx <= n && ny >= 1 && ny <= m && lev[nx][ny] > lv + 1);
}
void bfs(int x, int y)
{
    queue<pii> q;
    q.push({x, y});
    lev[x][y] = 0;
    while (!q.empty())
    {
        int tx = q.front().ff, ty = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tx + dr[i], ny = ty + dc[i];
            if (valid(nx, ny, lev[tx][ty]))
            {
                q.push({nx, ny});
                lev[nx][ny] = lev[tx][ty] + 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    lev.resize(n + 1, vi(m + 1, INT_MAX));
    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        bfs(x, y);
    }
    int mx = -1;
    pii ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (lev[i][j] > mx)
            {
                mx = lev[i][j];
                ans = {i, j};
            }
        }
    }
    cout << ans.ff << " " << ans.ss << endl;
    return 0;
}
