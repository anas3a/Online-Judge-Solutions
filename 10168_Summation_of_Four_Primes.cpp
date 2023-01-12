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

ll n = 10000000;
vector<bool> v(n + 1, true);
vi prime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (v[i])
        {
            for (ll j = i * i; j <= n; j += i)
                v[j] = false;
            prime.pb(i);
        }
    }
    ll x;
    while (cin >> x)
    {
        if (x < 8)
            cout << "Impossible." << endl;
        else
        {
            ll a, b;
            if (x & 1)
            {
                a = 5;
                b = x - 5;
            }
            else
            {
                a = x / 2, b = x / 2;
                if ((a & 1) && (b & 1))
                    a++, b--;
            }
            vi ans;
            bool f1 = true, f2 = true;
            for (int i = 0; i < sz(prime); i++)
            {
                if (f1 && v[a - prime[i]])
                {
                    ans.pb(prime[i]);
                    ans.pb(a - prime[i]);
                    f1 = false;
                }
                if (f2 && v[b - prime[i]])
                {
                    ans.pb(prime[i]);
                    ans.pb(b - prime[i]);
                    f2 = false;
                }
                if (sz(ans) == 4)
                    break;
            }
            cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
        }
    }
    return 0;
}
