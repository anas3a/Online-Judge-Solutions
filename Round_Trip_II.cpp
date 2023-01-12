#include <iostream>
#include <vector>
using namespace std;

int n, start, endx;
vector<int> v[200005];
int col[200005];
int par[200005];
void dfs(int u)
{
    col[u] = 1;
    for (int i = 0; i < v[u].size(); i++)
    {
        if (col[v[u][i]] == 0)
        {
            par[v[u][i]] = u;
            dfs(v[u][i]);
        }
        if (col[v[u][i]] == 1)
        {
            start = v[u][i];
            endx = u;
            break;
        }
    }
    col[u] = 2;
}
int main()
{
    cin >> n;
    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    start = endx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (start != -1)
            break;
        if (col[i] != 0)
            continue;
        dfs(i);
    }
    if (start == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        int ans[200005];
        int cx = 0;
        ans[cx++] = start;
        for (int i = endx;; i = par[i])
        {
            ans[cx++] = i;
            if (i == start)
                break;
        }
        cout << cx << endl;
        for (int i = cx - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
}