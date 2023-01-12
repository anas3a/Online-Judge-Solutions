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
        ll n, m, rb, rd, cb, cd;
        cin >> n >> m >> rb >> rd >> cb >> cd;
        ll cx = INT_MAX, cy = INT_MAX;
        if (rb <= cb)
            cx = cb - rb;
        else 
        {
            cx = n - rb;
            cx += n - cb;
        }
        if (rd <= cd)
            cy = cd - rd;
        else 
        {
            cy = m - rd;
            cy += m - cd;
        }
        cout << min(cx, cy) << endl;
    }
    return 0;
}