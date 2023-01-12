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

vvi v;
int n, m;
bool f(ll mid)
{
    set<int> s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s.count(i))
            continue;
        s.insert(i);
        cnt++;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (s.count(v[i][j]))
                continue;
            s.insert(v[i][j]);
            break;
        }
    }
    return cnt <= mid;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        v.clear();
        v.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        ll low = -1, high = n + 1;
        while (low + 1 < high)
        {
            ll mid = (low + high) / 2;
            if (f(mid))
                high = mid;
            else
                low = mid;
        }
        cout << high << endl;
    }
    return 0;
}
