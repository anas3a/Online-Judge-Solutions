#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        n = max(n, 6ll);
        if (n & 1)
            n++;
        cout << (n / 2) * 5 << endl;
    }
    return 0;
}