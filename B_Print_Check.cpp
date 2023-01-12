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

    ll n, m, k;
    cin >> n >> m >> k;
    vpl vr(n + 1, {0, 0}), vc(m + 1, {0, 0});
    for (int i = 1; i <= k; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
            vr[y] = {z, i};
        else
            vc[y] = {z, i};
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vr[i].ss > vc[j].ss)
                cout << vr[i].ff << " ";
            else
                cout << vc[j].ff << " ";
        }
        cout << endl;
    }
    return 0;
}
