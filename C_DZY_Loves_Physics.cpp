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

    ll n, m, nsum = 0, esum = 0;
    cin >> n >> m;
    vpl v;
    vector<vpi> graph(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        nsum += a;
        v.pb({a, i});
    }
    for (int i = 1; i <= m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
        esum += c;
    }
    double ans = 0;
    if (esum == 0)
    {
        cout << fixed << setprecision(15) << ans << endl;
        return 0;
    }
    ans = nsum / (double)esum;
    sort(all(v));
    vector<bool> choosen(n + 1, true);
    for (int i = 0; i < sz(v); i++)
    {
        ll xx = nsum, yy = esum;
        xx -= v[i].ff;
        ll u = v[i].ss;
        ll sum = 0;
        for (auto &j : graph[u])
        {
            if (choosen[j.ff])
                sum += j.ss;
        }
        yy -= sum;
        if (yy <= 0)
            continue;
        if (sum == 0)
        {
            nsum -= v[i].ff;
            ans = nsum / (double) esum;
            choosen[u] = false;
            continue;
        }
        double zz = xx / (double) yy;
        if (zz > ans)
        {
            ans = zz;
            nsum = xx;
            esum = yy;
            choosen[u] = false;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
