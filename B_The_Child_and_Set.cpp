#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll sum, limit, x;
    cin >> sum >> limit;
    x = sum;
    vll v;
    for (int i = limit; i >= 2; i--)
    {
        if (i & 1)
            continue;
        ll z = i & (-i);
        if (z <= x)
        {
            x -= z;
            v.pb(i);
        }
        if (x == 0)
            break;
    }
    for (int i = 1; i <= limit; i += 2)
    {
        if (x == 0)
            break;
        x--;
        v.pb(i);
    }
    if (x != 0)
        cout << -1 << endl;
    else
    {
        cout << v.size() << endl;
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
