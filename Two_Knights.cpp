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

    ll n, x = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll z = i * i;
        z = (z * (z - 1)) / 2;
        if (i != 1)
            x += (8 * (i - 2));
        z -= x;
        cout << max(0ll, z) << endl;
    }
    return 0;
}
