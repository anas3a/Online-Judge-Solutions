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

ll b;

ll f(ll n, ll m)
{
    if (m == 0)
        return 1;
    if (m % 2 == 0)
    {
        ll r = f(n, m / 2);
        return ((r % b) * (r % b)) % b;
    }
    else
        return ((n % b) * (f(n, m - 1) % b)) % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a;
    cin >> a >> b;
    ll x = f(3, a);
    cout << (x - 1 + b) % b << endl;
    return 0;
}
