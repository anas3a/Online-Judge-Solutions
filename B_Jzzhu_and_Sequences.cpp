#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpi = vector<pii>;
using vpl = vector<pll>;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define dg(x) cout << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, c, d, n = 1000000007;
    cin >> a >> b >> c;
    d = b - a;
    ll x = c / 3;
    if (c % 3 != 0)
        x++;
    if (c % 3 == 1)
    {
        if (!(x & 1))
            a *= -1;
        cout << (a + n) % n << endl;
    }
    else if (c % 3 == 2)
    {
        if (!(x & 1))
            b *= -1;
        cout << (b + n) % n << endl;
    }
    else if (c % 3 == 0)
    {
        if (!(x & 1))
            d *= -1;
        cout << ((d % n) + n) % n << endl;
    }
    return 0;
}
