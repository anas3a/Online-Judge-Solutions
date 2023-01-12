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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, minx, maxx, odd, even, x;
        cin >> n >> minx >> maxx;
        x = maxx - minx + 1;
        odd = x / 2, even = x / 2;
        if (x & 1)
        {
            if (minx & 1)
                odd++;
            else
                even++;
        }
        ll a1 = 0, a2 = 0;
        ll x1 = 3, x2 = 4;
        for (int i = 0; i < n; i++)
        {
            ll w, b;
            cin >> w >> b;
            x1 *= w;
            x1 += b;
            x2 *= w;
            x2 += b;
        }
        if (x1 & 1)
            a2 += odd;
        else
            a1 += odd;
        if (x2 & 1)
            a2 += even;
        else
            a1 += even;
        cout << a1 << " " << a2 << endl;
    }
    return 0;
}
