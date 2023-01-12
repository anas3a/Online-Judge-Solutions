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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll xx = min(x, y);
        ll yy = max(x, y);
        if (xx != 0 || yy == 0)
        {
            cout << -1 << endl;
            continue;
        }
        if ((n - 1) % yy != 0)
        {
            cout << -1 << endl;
            continue;
        }
        ll xy = 1;
        for (int i = 1, k = 1; i < n; i++, k++)
        {
            cout << xy << " ";
            if (k == yy)
            {
                xy = i + 2;
                k = 0;
            }
        }
        cout << endl;
    }
    return 0;
}