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

    ll n, m;
    cin >> n >> m;
    ll x, y;
    cin >> x >> y;
    ll k, cnt = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        ll a, b, cntx = LLONG_MAX;
        cin >> a >> b;
        if (a > 0)
            cntx = (n - x) / a;
        if (a < 0)
            cntx = (x - 1) / abs(a);
        if (b > 0)
            cntx = min(cntx, (m - y) / b);
        if (b < 0)
            cntx = min(cntx, (y - 1) / abs(b));
        cnt += cntx;
        x += cntx * a;
        y += cntx * b;
    }
    cout << cnt << endl;
    return 0;
}
