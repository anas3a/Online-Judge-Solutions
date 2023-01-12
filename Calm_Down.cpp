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
        double r1;
        ll n;
        cin >> r1 >> n;
        double l = 0, r = r1, circum = 2 * 2 * acos(0.0) * r1;
        for (int i = 0; i < 100; i++)
        {
            double m = (l + r) / 2;
            double circumhalf = (2 * 2 * acos(0.0) * m) / 2;
            if (circumhalf * n < circum)
                l = m;
            else
                r = m;
        }
        cout << "Case " << ++cs << ": " << l << endl;
    }
    return 0;
}