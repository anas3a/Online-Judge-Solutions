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
        ll ox, oy, ax, ay, bx, by;
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        double mx = (ax + bx) / 2.0, my = (ay + by) / 2.0;
        double oa = sqrt(((ox - ax) * (ox - ax)) + ((oy - ay) * (oy - ay)));
        double oc = sqrt(((ox - mx) * (ox - mx)) + ((oy - my) * (oy - my)));
        double a = acos(oc / oa) * 2; 
        double length = a * oa;
        cout << fixed << setprecision(12) << "Case " << ++cs << ": " << length << endl;
    }
    return 0;
}