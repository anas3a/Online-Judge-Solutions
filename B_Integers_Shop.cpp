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
        ll mn = LLONG_MAX, mx = LLONG_MIN, ans = 0;
        ll c1 = 0, c2 = 0;
        ll ind1 = 0, ind2 = 0;
        ll d = LONG_LONG_MAX;
        ll ix = -1, iy = -1;
        for (int i = 0; i < n; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            if (a < mn)
            {
                mn = a;
                ind1 = i;
                c1 = c;
            }
            else if (a == mn)
            {
                if (c < c1)
                {
                    c1 = c;
                    ind1 = i;
                }
            }
            if (b > mx)
            {
                mx = b;
                ind2 = i;
                c2 = c;
            }
            else if (b == mx)
            {
                if (c < c2)
                {
                    c2 = c;
                    ind2 = i;
                }
            }
            if (a == mn && b == mx)
            {
                ix = mn, iy = mx;
                d = min(d, c);
            }
            if (ix == mn && iy == mx)
            {
                cout << min(d, c1 + c2) << endl;
            }
            else
                cout << c1 + c2 << endl;
        }
    }
    return 0;
}