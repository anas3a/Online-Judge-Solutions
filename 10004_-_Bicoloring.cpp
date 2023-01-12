#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v[300];
int color[300];
bool flag = true;
void dfs(int u, int col)
{
    color[u] = col;
    for (int i = 0; i < v[u].size(); i++)
    {
        if (color[v[u][i]] == -1)
            dfs(v[u][i], 1 - col);
        else if (color[v[u][i]] == col)
        {
            flag = false;
        }
    }
}
int main()
{
    while (true)
    {
        int n, m;
        cin >> n;
        if (!n)
            break;
        cin >> m;
        for (int i = 0; i < 300; i++)
            v[i].clear(), color[i] = -1;
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        flag = true;
        dfs(0, 0);
        if (flag)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
}