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
        ll n, h, m;
        cin >> n >> h >> m;
        ll mz = m + (h * 60);
        ll h1, m1, ansx = LLONG_MAX, ans1, ans2;
        for (int i = 0; i < n; i++)
        {
            cin >> h1 >> m1;
            ll mx = m1 + (h1 * 60);
            if (mx >= mz)
                ansx = min(ansx, mx - mz);
            else
                ansx = min(ansx, mx + (24 * 60) - mz);
        }
        ans1 = ansx / 60, ans2 = ansx % 60;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}