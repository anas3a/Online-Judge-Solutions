#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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
        ll s, d;
        cin >> s >> d;
        if (s < d)
            cout << "impossible" << endl;
        else
        {
            ll x, y = (s - d) / 2;
            x = s - y;
            if (x + y == s && abs(x - y) == d)
                cout << x << " " << y << endl;
            else
                cout << "impossible" << endl;
        }
    }
    return 0;
}
