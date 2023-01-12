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

    ll n, x, mn = INT_MAX;
    cin >> n >> x;
    vll v(n), vx;
    x--;
    for (auto &i : v)
        cin >> i, mn = min(i, mn);
    for (int i = 0; i < n; i++)
    {
        if (v[i] == mn)
            vx.pb(i);
    }
    ll z = lower_bound(all(vx), x) - vx.begin();
    if (z == sz(vx) || vx[z] != x)
        z--;
    if (z == -1)
    {
        ll p = vx.back();
        ll q = (mn * n) + (n - p + x);
        v[p] = q;
        for (int i = 0; i < n; i++)
        {
            if (i == p)
                continue;
            if (i > p)
                v[i] -= mn + 1;
            else if (i <= x)
                v[i] -= mn + 1;
            else
                v[i] -= mn;
        }
    }
    else
    {
        ll p = vx[z];
        ll q = (mn * n) + (x - p);
        v[p] = q;
        for (int i = 0; i < n; i++)
        {
            if (i == p)
                continue;
            if (i > p && i <= x)
                v[i] -= mn + 1;
            else
                v[i] -= mn;
        }
    }
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
