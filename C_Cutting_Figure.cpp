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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int n, m;
vector<string> adj;
vector<vector<bool>> visited;
vector<vector<int>> tin, low;
int timer;
vector<pair<int, int>> is_bridge;
vector<pii> is_articulation_point;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(pii v, pii p = {-1, -1})
{
    visited[v.ff][v.ss] = true;
    tin[v.ff][v.ss] = low[v.ff][v.ss] = timer++;
    int children = 0;
    for (int i = 0; i < 4; i++)
    {
        pii to;
        to.ff = v.ff + dx[i];
        to.ss = v.ss + dy[i];
        if (to == p || to.ff >= n || to.ff < 0 || to.ss >= m || to.ss < 0 || adj[to.ff][to.ss] == '.')
            continue;
        if (visited[to.ff][to.ss])
            low[v.ff][v.ss] = min(low[v.ff][v.ss], tin[to.ff][to.ss]);
        else
        {
            dfs(to, v);
            low[v.ff][v.ss] = min(low[v.ff][v.ss], low[to.ff][to.ss]);
            if (low[to.ff][to.ss] >= tin[v.ff][v.ss] && p != mp(-1, -1))
                is_articulation_point.push_back(v);
            ++children;
        }
    }
    if (p == mp(-1, -1) && children > 1)
        is_articulation_point.push_back(v);
}

void find_articulationPoint_Bridge()
{
    timer = 0;
    visited.clear();
    tin.clear();
    low.clear();
    is_bridge.clear();
    is_articulation_point.clear();
    visited.assign(n, vector<bool>(m, false));
    tin.assign(n, vi(m, -1));
    low.assign(n, vi(m, -1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && adj[i][j] == '#')
            {
                dfs({i, j});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.resize(n);
    for (auto &i : adj)
        cin >> i;
    find_articulationPoint_Bridge();
    cout << sz(is_articulation_point) << nl;
    return 0;
}