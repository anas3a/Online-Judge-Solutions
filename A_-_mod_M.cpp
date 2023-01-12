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

    ll n;
    cin >> n;
    ll x = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        x = __gcd(a, x);
        mx = max(a, mx);
    }
    dg(x);
    if (mx <= 1)
        cout << 1 << endl;
    else if (x > 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    return 0;
}