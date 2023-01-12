#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a[100005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool flag = true;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (a[i] != a[j])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
