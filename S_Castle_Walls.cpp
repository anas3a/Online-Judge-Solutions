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

vi v;
void update(int i)
{
    while (i < sz(v))
    {
        v[i] += 1;
        i += (i & (-i));
    }
}

ll rsq(int i)
{
    ll sum = 0;
    while (i > 0)
    {
        sum += v[i];
        i -= (i & (-i));
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vpi v1(n), v2(m);
        v.clear();
        v.resize(n + m + 3, 0);
        for (auto &i : v1)
            cin >> i.ff >> i.ss;
        for (auto &i : v2)
            cin >> i.ff >> i.ss;
        sort(all(v1));
        sort(all(v2));
        ll ans = 0;
        for (int i = 0, j = 0; i < m; i++)
        {
            while (j < n && v1[j].ff < v2[i].ff)
                update(v1[j++].ss);
            ans += rsq(n + m + 2) - rsq(v2[i].ss - 1);
        }
        v.clear();
        v.resize(n + m + 3, 0);
        for (int i = m - 1, j = n - 1; i >= 0; i--)
        {
            while (j >= 0 && v1[j].ff > v2[i].ff)
                update(v1[j--].ss);
            ans += rsq(v2[i].ss);
        }
        cout << "Case " << ++cs << ": " << ans << '\n';
    }
    return 0;
}