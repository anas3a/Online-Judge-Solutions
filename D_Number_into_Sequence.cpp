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
    while (t--)
    {
        ll n;
        cin >> n;
        ll x = n, z = 1;
        vpl v;
        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ll cnt = 0;
                while (n % i == 0)
                {
                    n /= i;
                    cnt++;
                }
                if (cnt)
                    v.pb({cnt, i});
            }
        }
        if (n > 1)
            v.pb({1, n});
        sort(rall(v));
        cout << v[0].ff << endl;
        for (int i = 1; i < v[0].ff; i++)
            cout << v[0].ss << " ", z *= v[0].ss;
        cout << x / z << endl;
    }
    return 0;
}
