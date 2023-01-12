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
        multiset<ll> a, b;
        ll n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            b.insert(x);
        }
        vll va, vb;
        for (auto &i : a)
        {
            auto it = b.find(i);
            if (it != b.end())
                b.erase(it);
            else
                va.pb(i);
        }
        for (auto &i : b)
            vb.pb(i);
        ll ans = 0;
        a.clear();
        b.clear();
        for (auto &i : va)
        {
            string tmp = to_string(i);
            if (sz(tmp) > 1)
            {
                ans++;
                i = sz(tmp);
            }
            a.insert(i);
        }
        for (auto &i : vb)
        {
            string tmp = to_string(i);
            if (sz(tmp) > 1)
            {
                ans++;
                i = sz(tmp);
            }
            b.insert(i);
        }
        vll vx;
        for (auto &i : a)
        {
            auto it = b.find(i);
            if (it != b.end())
                b.erase(it);
            else
                vx.pb(i);
        }
        for (auto &i : b)
            vx.pb(i);
        for (auto &i : vx)
        {
            if (i > 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}