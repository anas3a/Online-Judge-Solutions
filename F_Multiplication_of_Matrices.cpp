#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

ll a[101][101], b[101][101], c[101][101];
int main()
{
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2;
    for (int i = 0; i < a1; i++)
        for (int j = 0; j < a2; j++)
            cin >> a[i][j];
    cin >> b1 >> b2;
    c1 = a1, c2 = b2;
    for (int i = 0; i < b1; i++)
        for (int j = 0; j < b2; j++)
            cin >> b[i][j];
    for (int i = 0; i < a1; i++)
    {
        for (int j = 0; j < b2; j++)
        {
            for (int k = 0; k < a2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    return 0;
}
