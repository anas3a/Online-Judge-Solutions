#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, u, r, d, l;
        bool f = true;
        cin >> n >> u >> r >> d >> l;
        if (u == n && (l == 0 || r == 0))
            f = false;
        if (r == n && (l == 0 || r == 0))
            f = false;
        if (l == n && (u == 0 || d == 0))
            f = false;
        if (r == n && (u == 0 || d == 0))
            f = false;
        if (u == n - 1 && (l + r == 0))
            f = false;
        if (d == n - 1 && (l + r == 0))
            f = false;
        if (l == n - 1 && (u + d == 0))
            f = false;
        if (r == n - 1 && (u + d == 0))
            f = false;
        if (u == n && d == n && (l < 2 || r < 2))
            f = false;
        if (l == n && r == n && (u < 2 || d < 2))
            f = false;
        if (u == n - 1 && d == n - 1 && l + r < 2)
            f = false;
        if (l == n - 1 && r == n - 1 && u + d < 2)
            f = false;
        if (u + d == 2 * n - 1 && (l == 0 || r == 0 || l + r < 3))
            f = false;
        if (r + l == 2 * n - 1 && (u == 0 || d == 0 || u + d < 3))
            f = false;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}