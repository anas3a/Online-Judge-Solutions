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

ll mx = 2e5;
vector<bool> is_prime(mx + 5, true);
vll prime;

bool overflow(ll a, ll b)
{
    long long mul = a * b;
    return ((mul / a) != b);
}

void sieve()
{
    is_prime[0] = is_prime[1] = false;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    set<ll> st;
    map<ll, pll> mp;
    for (int i = 3; i <= 15; i++)
    {
        int k = 0;
        while (k + i <= sz(prime))
        {
            ll candidate = 1;
            bool flag = true;
            for (int j = k; j - k < i; j++)
            {
                if (overflow(candidate, prime[j]))
                {
                    flag = false;
                    break;
                }
                candidate *= prime[j];
            }
            if (flag)
            {
                st.insert(candidate);
                mp[candidate] = {k, k + i};
            }
            k++;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (!st.count(n))
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = mp[n].ff; i < mp[n].ss; i++)
                cout << prime[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
