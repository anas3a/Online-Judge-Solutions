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

    ll t, c = 0;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        vll v(k);
        for (auto &i : v)
            cin >> i;
        sort(all(v));
        if (k == 1)
        {
            cout << "Case " << ++c << ": " << v[0] * v[0] << endl;
            continue;
        }
        ll lc = 1;
        for (auto &i : v)
        {
            lc = (lc / __gcd(lc, i)) * i;
        }
        if (lc == v[k - 1])
            lc *= 2;
        cout << "Case " << ++c << ": " << lc << endl;
    }
    return 0;
}
