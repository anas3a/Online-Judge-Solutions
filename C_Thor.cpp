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

    int n, q, cnt = 0, cx = 1;
    cin >> n >> q;
    vvi v(n + 1);
    set<int> s;
    for (int i = 1; i <= q; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            v[x].pb(cx);
            s.insert(cx);
            cout << sz(s) << endl;
            cx++;
        }
        if (t == 2)
        {
            for (int j = 0; j < sz(v[x]); j++)
                s.erase(v[x][j]);
            v[x].clear();
            cout << sz(s) << endl;
        }
        if (t == 3)
        {
            ll z = *s.upper_bound(x);
            while (!s.empty() && *s.begin() < z)
                s.erase(s.begin());
            if (!s.empty() && *s.rbegin() == x)
                s.clear();
            cout << sz(s) << endl;
        }
    }
    return 0;
}
