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

    ll n, m, cnt = 0;
    cin >> n;
    vector<pair<pll, ll>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].ff.ff >> v[i].ff.ss, v[i].ss = i;
    sort(all(v));
    cin >> m;
    vll ans(n, -1);
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        pair<pll, ll> tm = {{x, -1}, -1};
        ll in = lower_bound(all(v), tm) - v.begin();
        if (in != n && ans[v[in].second] == -1)
        {
            if ((x - v[in].first.first) * (x - v[in].first.first) + (y * y) <= v[in].first.second * v[in].first.second)
                ans[v[in].second] = i, cnt++;
        }
        in--;
        if (in >= 0 && ans[v[in].second] == -1)
        {
            if ((x - v[in].first.first) * (x - v[in].first.first) + (y * y) <= v[in].first.second * v[in].first.second)
                ans[v[in].second] = i, cnt++;
        }
    }
    cout << cnt << endl;
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
