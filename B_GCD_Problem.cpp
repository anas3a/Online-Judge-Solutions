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
        ll n;
        cin >> n;
        ll a = n / 2, b;
        if (n & 1)
        {
            for (ll i = 3; i <= i * i <= n; i++)
            {
                ll x = (n - 1) - i;
                ll y = (n - 1) - x;
                if (__gcd(x, y) == 1)
                {
                    cout << x << " " << y << " " << 1 << endl;
                    break;
                }
            }
        }
        else
        {
            b = a - 1;
            cout << a << " " << b << " " << 1 << endl;
        }
    }
    return 0;
}