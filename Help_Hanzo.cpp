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

vector<long long> primes;
void sieve()
{
    long long lim = 1e5;
    vector<char> mark(lim + 1, false);
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
}

ll segmentedSieve(long long L, long long R)
{
    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    ll cnt = 0;
    for (ll i = 0; i < sz(isPrime); i++)
    {
        if (isPrime[i])
            cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    ll t, cs = 0;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << "Case " << ++cs << ": " << segmentedSieve(a, b) << endl;
    }
    return 0;
}