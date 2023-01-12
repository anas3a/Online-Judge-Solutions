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

vll prime;
vector<bool> is_prime;
ll n = 1299720;

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.pb(i);
        for (ll j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    is_prime.resize(n + 2, true);
    sieve();
    dg(sz(prime));
    while (true)
    {
        ll x;
        cin >> x;
        if (!x)
            break;
        if (is_prime[x])
            cout << 0 << endl;
        else
        {
            ll pos = lower_bound(all(prime), x) - prime.begin();
            cout << prime[pos] - prime[pos - 1] << endl;
        }
    }
    return 0;
}
