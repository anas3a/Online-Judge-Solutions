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

struct edge
{
    ll a, b, c;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, x, mx = 1e16;
    cin >> n >> m;
    vector<edge> v(m);
    for (auto &i : v)
        cin >> i.a >> i.b >> i.c;
    vll dist(n + 1, mx);
    vll p(n + 1, -1);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto &j : v)
        {
            if (dist[j.b] > dist[j.a] + j.c)
            {
                dist[j.b] = dist[j.a] + j.c;
                p[j.b] = j.a;
                x = j.b;
            }
        }
    }
    if (x == -1)
        cout << "NO" << endl;
    else
    {
        int y = x;
        for (int i = 0; i < n; i++)
            y = p[y];
        vll ans;
        for (int i = y; i != -1; i = p[i])
        {
            ans.pb(i);
            if (i == y && sz(ans) > 1)
                break;
        }
        reverse(all(ans));
        cout << "YES" << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
