#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    char a[102][102];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

    int l, r;
    cin >> l >> r;
    bool f = true;
    for (int i = 0; i < 8; i++)
    {
        int x = l + dx[i];
        int y = r + dy[i];
        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.')
            f = false;
    }
    if (f)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
