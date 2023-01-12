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

    ll vp, vd, t, f, c, ans = 0, cx = 0;
    cin >> vp >> vd >> t >> f >> c;
    int x = 1, p = 0, d = 0;
    for (int i = 0, j = 0;; i++)
    {
        p += vp;
        if (p >= c)
            break;
        if (i < t)
            continue;
        if (x == 1)
            d += vd;
        else if (x == 2)
            d -= vd;
        else if (x == 3)
            j++;
        if (j == f)
            x = 1;
        dg(d);
        dg(p);
        if (d >= p && x == 1)
        {
            ans++;
            x = 2;
            j = 0;
            dg(i);
        }
        if (d <= 0 && x == 2)
        {
            d = 0;
            x = 3;
            j = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
