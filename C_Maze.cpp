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

ll n, m, k, cnt = 0, a, cx = 0;
vector<string> graph;
vector<vector<bool>> visited;

void sol()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && graph[i][j] == '.')
                graph[i][j] = 'X';
        }
    }
    cx = 1e5;
}

void dfs(int i, int j)
{
    visited[i][j] = true;
    cx++;
    if (cx == a)
        sol();
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int l = 0; l < 4; l++)
    {
        int x = i + dx[l], y = j + dy[l];
        if (x >= n || x < 0 || y >= m || y < 0 || visited[x][y] || graph[x][y] != '.')
            continue;
        dfs(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    graph.resize(n);
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.')
                cnt++;
        }
    }
    a = cnt - k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' && !visited[i][j])
                dfs(i, j);
        }
    }
    for (auto &i : graph)
        cout << i << endl;
    return 0;
}
