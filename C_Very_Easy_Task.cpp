#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

ll n, x, y, l, r;
bool f(ll z)
{
    return ((z / x) + (z / y)) >= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y;
    l = 0, r = 1;
    n--;
    if (n == 0)
    {
        cout << min(x, y) << endl;
        return 0;
    }
    while (!f(r))
        r *= 2;
    r += max(x, y);
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (f(m))
            r = m;
        else
            l = m;
    }
    cout << r + min(x, y) << endl;
    return 0;
}
