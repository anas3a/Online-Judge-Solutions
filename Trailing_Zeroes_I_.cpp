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

ll n = 1e6 + 6;
vector<bool> is_prime(n + 3, true);
vll prime;
void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime.pb(i);
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        ll nx;
        cin >> nx;
        ll ans = 1;
        for (auto &i : prime)
        {
            if (i * i > nx)
                break;
            ll cnt = 0;
            while (nx % i == 0)
            {
                nx /= i;
                cnt++;
            }
            ans *= (cnt + 1);
        }
        if (nx != 1)
            ans *= 2;
        cout << "Case " << ++cs << ": " << ans - 1 << endl;
    }
    return 0;
}