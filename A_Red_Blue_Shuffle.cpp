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
        ll n, cr = 0, cb = 0;
        string r, b;
        cin >> n >> r >> b;
        for (int i = 0; i < n; i++)
        {
            if (r[i] > b[i])
                cr++;
            else if (b[i] > r[i])
                cb++;
        }
        if (cr > cb)
            cout << "RED" << endl;
        else if (cb > cr)
            cout << "BLUE" << endl;
        else
            cout << "EQUAL" << endl;
    }
    return 0;
}
