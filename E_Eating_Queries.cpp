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
        ll n, q;
        cin >> n >> q;
        vll v(n);
        for (auto &i : v)
            cin >> i;
        sort(rall(v));
        ll sum = 0;
        vll vx;
        for (auto &i : v)
        {
            sum += i;
            vx.pb(sum);
        }
        while (q--)
        {
            ll x;
            cin >> x;
            if (x > vx.back())
                cout << -1 << endl;
            else
                cout << lower_bound(all(vx), x) - vx.begin() + 1<< endl;
        }
    }
    return 0;
}