#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int a[31][31];
int main()
{
    int n;
    cin >> n;
    a[1][1] = 1;
    for (int i = 2; i <= 30; i++)
        for (int j = 1; j <= 30; j++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
