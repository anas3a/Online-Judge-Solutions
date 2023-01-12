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

bool is_prime(ll n)
{
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

    while (true)
    {
        ll n;
        cin >> n;
        if (n == 0)
            break;
        ll x = (1ll << n) - 1, y = (1ll << (n - 1));
        if (!is_prime(n))
            cout << "Given number is NOT prime! NO perfect number is available." << endl;
        else if (!is_prime(x))
            cout << "Given number is prime. But, NO perfect number is available." << endl;
        else
            cout << "Perfect: " << x * y << "!" << endl;
    }
    return 0;
}
