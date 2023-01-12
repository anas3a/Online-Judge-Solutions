#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector <int>;
using vll = vector <ll>;
using vvi = vector <vi >;
using vvl = vector <vll >;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vpi = vector <pii >;
using vpl = vector <pll >;

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

    ll t, cs = 0;
    cin >> t;
    while(t--)
    {
        ll r1, r2, h, p;
        cin >> r1 >> r2 >> h >> p;
        double rx = (r1 - r2) / (double) h;
        rx = r1 - (rx * (h - p));
        double volum = (1 / 3.0) * 2 * acos(0.0) * ((rx * rx) + (r2 * r2) + (rx * r2)) * p;
        cout << fixed << setprecision(9) << "Case " << ++cs << ": " << volum << endl;
    }
    return 0;
}