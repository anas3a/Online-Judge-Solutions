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

bool comp(pii &a, pii &b)
{
    if (a.ff == b.ff)
        return a.ss > b.ss;
    return a.ff < b.ff;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vpi v(n);
    for (auto &i : v)
        cin >> i.ff;
    for (auto &i : v)
        cin >> i.ss;
    sort(all(v), comp);
    vi ans;
    multiset<int> vx;
    for (int i = 0; i < n; i++)
    {
        vx.insert(v[i].ss);
        int ind = distance(vx.begin(), vx.lower_bound(v[i].ss));
        ans.pb(sz(vx) - ind);
    }
    ll ansx = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] == v[i + 1])
            ans[i] = ans[i + 1];
        ansx += ans[i];
    }
    ansx += ans[n - 1];
    cout << ansx << endl;
    return 0;
}