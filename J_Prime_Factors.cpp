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

vector<bool> p;
vll prime;
void is_prime(ll n)
{
    p[0] = p[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (p[i])
        {
            prime.pb(i);
            for (ll j = i * i; j <= n; j += i)
                p[j] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    p.resize(n + 5, true);
    is_prime(n);
    int i = 0;
    vpl ans;
    while (prime[i] * prime[i] <= n)
    {
        int cnt = 0;
        while (n % prime[i] == 0)
            n /= prime[i], cnt++;
        if (cnt)
            ans.pb({prime[i], cnt});
        i++;
    }
    if (n != 1)
        ans.pb({n, 1});
    for (int i = 0; i < sz(ans); i++)
    {
        if (i != 0)
            cout << "*";
        cout << "(" << ans[i].ff << "^" << ans[i].ss << ")";
    }
    cout << endl;
    return 0;
}
