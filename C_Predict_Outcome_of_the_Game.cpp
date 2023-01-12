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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        ll a = max(d1, d2), b = min(d1, d2);
        ll z = (a - b) + a, y = a + b;
        if (b == 0 && (k & 1))
            y += a;
        if (z <= n - k && (n - k - z) % 3 == 0)
            cout << "yes" << endl;
        else if (y <= n - k && (n - k - y) % 3 == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
