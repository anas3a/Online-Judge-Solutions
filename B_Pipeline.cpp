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

ll n, k, x;
bool f(ll m)
{
    ll z = k - m;
    ll y = (z * (z - 1) / 2);
    return x - y >= n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    x = k * (k - 1) / 2 + 1;
    if (x < n)
        cout << -1 << endl;
    else
    {
        ll l = -1, r = k;
        while (l + 1 < r)
        {
            ll m = (l + r) / 2;
            if (f(m))
                r = m;
            else
                l = m;
        }
        cout << r << endl;
    }
    return 0;
}
