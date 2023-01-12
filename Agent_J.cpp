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
        double r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        double r12 = r1 + r2, r13 = r1 + r3, r23 = r2 + r3;
        double s = (r12 + r23 + r13) / 2;
        double areatri = sqrt(s * (s - r12) * (s - r23) * (s - r13));
        double a1 = acos(((r12 * r12) + (r13 * r13) - (r23 * r23)) / (2 * r12 * r13));
        double a2 = acos(((r23 * r23) + (r12 * r12) - (r13 * r13)) / (2 * r12 * r23));
        double a3 = acos(((r13 * r13) + (r23 * r23) - (r12 * r12)) / (2 * r13 * r23));
        double area1 = (a1 / 2) * r1 * r1;
        double area2 = (a2 / 2) * r2 * r2;
        double area3 = (a3 / 2) * r3 * r3;
        cout << fixed << setprecision(12) << "Case " << ++cs <<": " <<areatri - area1 - area2 - area3 << endl;
    }
    return 0;
}