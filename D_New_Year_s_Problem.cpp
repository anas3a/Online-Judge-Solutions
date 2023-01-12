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

vvl v;
ll n, m;
bool ok(ll md)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < m; j++)
        {
            if (v[j][i] >= md)
                flag = true;
        }
        if (!flag)
            return false;
    }
    ll cnt = 0;
    for (int i = 0; i < m; i++)
    {
        ll cntx = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] >= md)
                cntx++;
        }
        cnt = max(cnt, cntx);
    }
    return cnt >= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        v.clear();
        v.resize(m, vll(n));
        for (auto &i : v)
        {
            for (auto &j : i)
                cin >> j;
        }
        ll l = 1, r = 1;
        while (ok(r))
            r *= 2;
        while (l + 1 < r)
        {
            ll md = (l + r) / 2;
            if (ok(md))
                l = md;
            else
                r = md;
        }
        cout << l << endl;
    }
    return 0;
}