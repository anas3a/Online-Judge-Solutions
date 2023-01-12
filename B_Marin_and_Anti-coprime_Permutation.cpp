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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    ll md = 998244353;
    vll v(2e3, 1);
    for (ll i = 1; i <= 1e3 + 5; i++)
    {
        v[i] = (i * v[i - 1]) % md;
    }
    while (t--)
    {
        ll n;
        cin >> n;
        if (n & 1)
            cout << 0 << endl;
        else
        {
            n /= 2;
            cout << (v[n] * v[n]) % md << endl;
        }
    }
    return 0;
}