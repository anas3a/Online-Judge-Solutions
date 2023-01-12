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

bitset<10000010> bs;
vi primes;

void sieve()
{
    ll n = 10000000;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (bs[i])
        {
            for (ll j = i * i; j <= n; j += i)
                bs[j] = 0;
            primes.pb(i);
        }
    }
}
bool isprime(ll n)
{
    if (n < 10000000)
        return bs[n];
    for (auto &i : primes)
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

    int n;
    cin >> n;
    vll v(n);
    for (auto &i : v)
        cin >> i;
    sort(all(v));
    sieve();
    ll mn = 2, mx = 2;
    mx = mn = v[n / 2];
    while (mx >= 2 && !isprime(mx))
        mx++;
    while (mn >= 2 && !isprime(mn))
        mn--;
    mx = max(mx, 2ll), mn = max(mn, 2ll);
    ll ans1 = 0, ans2 = 0;
    for (auto &i : v)
        ans1 += abs(i - mn), ans2 += abs(i - mx);
    cout << min(ans1, ans2) << endl;
    return 0;
}