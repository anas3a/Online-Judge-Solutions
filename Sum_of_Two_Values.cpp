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

    ll n, x;
    cin >> n >> x;
    vpl v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].ff;
        v[i].ss = i + 1;
    }
    sort(all(v));
    for (int i = 0, j = n - 1; i < j; i++)
    {
        while (j > i && v[i].ff + v[j].ff > x)
            j--;
        if (v[i].ff + v[j].ff == x && v[i].ss != v[j].ss)
        {
            cout << v[i].ss << " " << v[j].ss << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
