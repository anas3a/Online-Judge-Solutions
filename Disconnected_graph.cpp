#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > g;
vector <bool> vis;

void dfs(int v) {
    vis[v] = true;
    for (int u : g[v]) {
        if (!vis[u])
            dfs(u);
    }
}
int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        g.clear();
        g.resize(n + 2);
        vis.clear();
        vis.resize(n + 2, false);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] != true)
            {
                x++;
                dfs(i);
            }
        }
        cout << "Case " << c++ << ": " << x << endl;
    }
    return 0;
}
