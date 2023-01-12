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
        ll ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        ll abx = bx - ax, aby = by - ay;
        ll dx = cx - abx, dy = cy - aby;
        double disab = sqrt(((bx - ax) * (bx  - ax)) + ((by - ay) * (by - ay)));
        double disbc = sqrt(((bx - cx) * (bx - cx)) + ((by - cy) * (by - cy)));
        double disac = sqrt(((ax - cx) * (ax - cx)) + ((ay - cy) * (ay - cy)));
        double s = (disab + disbc + disac) / 2;
        double areatri = sqrt(s * (s - disab) * (s - disbc) * (s - disac));
        cout << "Case " << ++cs << ": " << dx << " " << dy << " " << (ll) round (areatri * 2) << endl;
    }
    return 0;
}