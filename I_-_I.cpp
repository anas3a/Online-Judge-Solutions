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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

ll h, s;
double a1, a2;
bool f(double m)
{
    ll hx = h * h;
    double b = hx - m;
    double areax = 0.5 * sqrt(m) * sqrt(b);
    a1 = sqrt(m);
    a2 = sqrt(b);
    return areax < s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> h >> s;
        ll hx = h * h;
        double a = sqrt(hx / 2.0);
        if (a * a * 0.5 < s)
        {
            if (s - (a * a * 0.5) > 1e-2)
            {
                cout << -1 << nl;
                continue;
            }
        }
        double l = 0, r = hx / 2.0;
        for (int i = 0; i < 500; i++)
        {
            double m = (l + r) / 2.0;
            if (f(m))
                l = m;
            else
                r = m;
        }
        cout << fixed << setprecision(8) << min(a1, a2) << " " << max(a1, a2) << " " << h << nl;
    }
    return 0;
}