#include <bits/stdc++.h>

using namespace std;

#define int long long

int arr[] = {0, 0, -1, +1};
int brr[] = {-1, +1, 0, 0};
bool vis[1005][1005];
int fx, fy;
int mn;
int t, n, m, pos1x, pos1y, pos2x, pos2y;
char ch[1005][1005];
bool yes1, yes2;
int tmp = INT_MAX;
void bfs(int x, int y, int curr)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    vis[x][y] = 1;
    while (!q.empty())
    {
        int topx = q.front().first.first;
        int topy = q.front().first.second;
        int value = q.front().second;
        q.pop();
        if (value > tmp)
        {
            yes1 = true;
            break;
        }
        if (ch[topx][topy] == 'S')
        {
            if (curr == 0)
                tmp = value;
        }
        if (ch[topx][topy] == 'F')
            break;
        if (yes1 && yes2)
            break;
        for (int i = 0; i < 4; i++)
        {
            int a = topx + arr[i];
            int b = topy + brr[i];
            if (curr == 0 && a >= 1 && a <= n && b >= 1 && b <= m && ch[a][b] != '#' && !vis[a][b])
            {
                vis[a][b] = 1;
                q.push({{a, b}, value + 1});
            }
        }
    }
}

int32_t main()
{
    //ios_base:: sync_with_stdio(false);cin.tie(0);

    scanf("%lld", &t);
    for (int kase = 1; kase <= t; kase++)
    {
        int cnt = 0;
        int ase1 = false, ase2 = false, ase3 = false;
        scanf("%lld %lld", &n, &m);
        getchar();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &ch[i][j]);
                if (ch[i][j] == 'E')
                {
                    fx = i;
                    fy = j;
                    ase2 = true;
                }
                if (ch[i][j] == 'S')
                {
                    cnt++;
                }
            }
            getchar();
        }
        assert(cnt == 1);
        yes1 = false, yes2 = false;
        memset(vis, 0, sizeof(vis));
        bfs(fx, fy, 0);
        if (yes1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}