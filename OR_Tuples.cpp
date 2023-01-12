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
        ll p, q, r;
        cin >> p >> q >> r;
        bitset<25> a(p);
        bitset<25> b(q);
        bitset<25> c(r);
        ll ans = 1;
        for (int i = 0; i < 25; i++)
        {
            ll cnt = a[i] + b[i] + c[i];
            if (cnt == 0)
                ans *= 1;
            if (cnt == 3)
                ans *= 4;
            if (cnt == 2)
                ans *= 1;
            if (cnt == 1)
                ans *= 0;
        }
        cout << ans << endl;
    }
    return 0;
}