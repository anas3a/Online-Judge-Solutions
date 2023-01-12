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

vector<string> g;
vector<vector<bool>> vis;
ll n, m, xx, yy, cnt;
char c;
bool flag = false;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void dfs(int i, int j)
{
    cnt++;
    vis[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (y == -1)
            y = m - 1;
        if (y == m)
            y = 0;
        if (x < 0 || x >= n || vis[x][y] || tolower(g[x][y]) != c)
            continue;
        dfs(x, y);
    }
    if (i == xx && j == yy)
        flag = true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n >> m)
    {
        g.clear();
        g.resize(n);
        vis.clear();
        vis.resize(n, vector<bool>(m, false));
        for (auto &i : g)
            cin >> i;
        cin >> xx >> yy;
        c = tolower(g[xx][yy]);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && tolower(g[i][j]) == c)
                {
                    cnt = 0;
                    dfs(i, j);
                    if (!flag)
                        ans = max(cnt, ans);
                    flag = false;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
