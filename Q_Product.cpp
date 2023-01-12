#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ll l, r, m;
    cin >> l >> r >> m;
    ll ans = 1;
    for (ll i = l; i <= r; i++)
        ans = (ans * i) % m;
    cout << ans << endl;
    return 0;
}
