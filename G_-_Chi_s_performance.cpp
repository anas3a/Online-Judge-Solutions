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

    ll n;
    cin >> n;
    map<ll, vll> m;
    for (int i = 0; i < n; i++)
    {
        ll v, p;
        cin >> v >> p;
        m[v].pb(p);
    }
    ll mn = 0, mx = 0;
    for (auto &i : m)
        sort(all(i.ss));
    ll ans = 0;
    map<ll, vll>::iterator it1 = m.begin(), it2 = m.begin();
    it1++;
    while (it1 != m.end())
    {
        vpl vx;
        if (!mn)
        {
            vx.pb({abs(it2->second.front() - it1->second.front()), 0});
            vx.pb({abs(it2->second.front() - it1->second.back()), 1});
        }
        else if (sz(it2->second) > 1)
        {
            vx.pb({abs(it2->second[1] - it1->second.front()), 0});
            vx.pb({abs(it2->second[1] - it1->second.back()), 1});
        }
        if (!mx)
        {
            vx.pb({abs(it2->second.back() - it1->second.front()), 0});
            vx.pb({abs(it2->second.back() - it1->second.back()), 1});
        }
        else if (sz(it2->second) > 1)
        {
            ll z = sz(it2->second);
            vx.pb({abs(it2->second[z - 2] - it1->second.front()), 0});
            vx.pb({abs(it2->second[z - 2] - it1->second.back()), 1});
        }
        it1++, it2++;
        sort(rall(vx));
        ans += vx[0].ff;
        if (vx[0].ss == 0)
        {
            mn = 1;
            mx = 0;
        }
        else
        {
            mx = 1;
            mn = 0;
        }
    }
    cout << ans << endl;
    return 0;
}