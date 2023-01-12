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

ll mx = 1e7;
vector<bool> is_prime(mx + 2, true);
vll prime;
void sieve()
{
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= mx; i++)
    {
        if (is_prime[i])
        {
            prime.pb(i);
            for (ll j = i * i; j <= mx; j += i)
                is_prime[j] = false;
        }
    }
}
bool check_prime(ll n)
{
    if (n == 1)
        return true;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    ll q;
    cin >> q;
    if (check_prime(q))
        cout << 1 << endl
             << 0 << endl;
    else
    {
        vll v;
        for (auto &i : prime)
        {
            if (i * i > q)
                break;
            while (q % i == 0)
            {
                v.pb(i);
                q /= i;
            }
        }
        if (q > 1)
            v.pb(q);
        if (sz(v) <= 2)
            cout << 2 << endl;
        else
            cout << 1 << endl
                 << v[0] * v[1] << endl;
    }
    return 0;
}
