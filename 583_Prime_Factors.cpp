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

    ll n = 1e6;
    vector<bool> v(n + 3, true);
    vi prime;
    ll nx;
    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (v[i])
        {
            prime.pb(i);
            for (ll j = i * i; j <= n; j += i)
                v[j] = false;
        }
    }
    while (true)
    {
        cin >> nx;
        if (nx == 0)
            break;
        ll x = abs(nx);
        vi ans;
        for (int i = 0; i < sz(prime); i++)
        {
            if (prime[i] * prime[i] > x)
                break;
            while (x % prime[i] == 0)
            {
                x /= prime[i];
                ans.pb(prime[i]);
            }
        }
        if (x > 1)
            ans.pb(x);
        cout << nx << " = ";
        if (nx < 0)
            cout << -1;
        for (int i = 0; i < sz(ans); i++)
        {
            if (i != 0 || nx < 0)
                cout << " x ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
