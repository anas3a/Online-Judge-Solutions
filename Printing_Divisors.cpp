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

ll nx = 1e3 + 7;
vector<bool> is_prime(nx + 3, true);
vll prime;
void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= nx; i++)
    {
        if (is_prime[i])
        {
            prime.pb(i);
            for (ll j = i * i; j <= nx; j += i)
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
    ll mx = 70000;
    vvi v(mx + 2);
    for (int i = 1; i <= mx; i++)
    {
        ll z = i;
        v[i].pb(1);
        for (auto &j : prime)
        {
            if (j * j > z)
                break;
            while (z % j == 0)
            {
                v[i].pb(j);
                z /= j;
            }
        }
        if (z > 1)
            v[i].pb(z);
    }

    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<vi, ll>> div;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                div.pb({v[i], i});
                if (i != n / i)
                    div.pb({v[n / i], n / i});
            }
        }
        sort(all(div));
        cout << "Case " << ++cs << ": " << endl;
        for (int i = 0; i < sz(div); i++)
        {
            if (i != 0)
                cout << " ";
            cout << div[i].ss;
        }
        cout << endl;
    }
    return 0;
}