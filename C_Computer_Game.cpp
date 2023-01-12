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

ll k, n, a, b;
bool f(ll x)
{
    if (x > n)
        return false;
    ll z = x * a;
    z += (n - x) * b;
    return k > z;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> q;
    while (q--)
    {
        cin >> k >> n >> a >> b;
        ll l = -1, r = n + 5;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (f(m))
                l = m;
            else
                r = m;
        }
        cout << l << endl;
    }
    return 0;
}
