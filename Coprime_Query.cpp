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

ll n = 200003;
vector<bool> is_prime(n + 1, true);
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

    ll n, q;
    cin >> n >> q;
    vll v(2e5 + 10, 0);
    sieve();
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v[a]++;
    }
    vll vx(2e5 + 10, 0);
    for (int i = 1; i <= 200000; i++)
    {
        for (int j = i; j <= 200000; j += i)
        {
            vx[i] += v[j];
        }
    }
    while (q--)
    {
        ll x;
        cin >> x;
        ll z = x;
        vll vy;
        for (auto &i : prime)
        {
            if (i * i > z)
                break;
            if (z % i == 0)
                vy.pb(i);
            while (z % i == 0)
                z /= i;
        }
        if (z != 1)
            vy.pb(z);
        // for (ll i = 2; i * i <= n; i++)
        // {
        //     if (z % i == 0)
        //     {
        //         vy.pb(i);
        //         if (i != (z / i))
        //             vy.pb(z / i);
        //     }
        // }
        ll sum = 0;
        for (int msk = 0; msk < (1 << vy.size()); ++msk)
        {
            ll mult = 1, bits = 0;
            for (int i = 0; i < (int)vy.size(); ++i)
            {
                if (msk & (1 << i))
                {
                    ++bits;
                    mult *= vy[i];
                }
            }
            if (bits == 0)
                continue;
            if (bits % 2 == 1 && mult <= 200000)
                sum += vx[mult];
            else if (bits % 2 == 0 && mult <= 200000)
                sum -= vx[mult];
        }
        cout << n - sum << endl;
    }
    return 0;
}