#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
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

ll m = 1e9 + 7;

ll f(ll n, ll p)
{
    if (p == 0)
        return 1;
    if (p % 2 == 0)
    {
        ll r = f(n, p / 2);
        return ((r % m) * (r % m)) % m;
    }
    else
        return ((n % m) * (f(n, p - 1) % m)) % m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll x = f(3, n * 3) - f(7, n);
    cout << ((x % m) + m) % m << endl;
    return 0;
}
