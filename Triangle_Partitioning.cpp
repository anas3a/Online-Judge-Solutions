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

    ll t, cs = 0;
    cin >> t;
    while (t--)
    {
        double ab, ac, bc, ratio;
        cin >> ab >> ac >> bc >> ratio;
        double l = 0, r = ab;
        for (int i = 0; i < 100; i++)
        {
            double m = (l + r) / 2;
            double x = (ab * ab) / (m * m);
            if ((1 / (x - 1)) < ratio)
                l = m;
            else
                r = m;
        }
        cout << fixed << setprecision(10) << "Case " << ++cs << ": " << l << endl;
    }
    return 0;
}