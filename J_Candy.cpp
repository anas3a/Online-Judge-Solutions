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
        ll n, m;
        cin >> n >> m;
        vll age(20, 0), can(60, 0);
        set<ll> vt, vtx;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            vt.insert(x);
            age[x]++;
        }
        for (int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            vtx.insert(x);
            can[x]++;
        }
        bool f = true;
        int cnt = 0;
        vll v, vx;
        for (auto &i : vt)
            v.pb(i);
        for (auto &i : vtx)
            vx.pb(i);
        reverse(all(v));
        reverse(all(vx));
        for (int i = 0, j = 0; i < sz(v); i++)
        {
            while (j < sz(vx) && can[vx[j]] < age[v[i]])
                j++;
            if (j < sz(vx) && can[vx[j]] >= age[v[i]])
                j++, cnt++;
        }
        if (cnt == sz(v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
