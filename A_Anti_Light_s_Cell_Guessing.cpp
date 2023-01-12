#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << endl;
        else if (n == 1 || m == 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}