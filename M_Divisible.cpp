#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    string n;
    ll x;
    cin >> n >> x;
    ll z = 0;
    for (int i = 0; i < n.size(); i++)
    {
        z += n[i] - '0';
        z %= x;
        z *= 10;
    }
    if (z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
