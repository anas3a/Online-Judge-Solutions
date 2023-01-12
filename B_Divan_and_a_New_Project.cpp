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
        ll n;
        cin >> n;
        vpl v(n + 1);
        vll vy(n + 1);
        for (int i = 1; i <= n; i++)
        {
            ll a;
            cin >> a;
            v.pb({a, i});
            vy[i] = a;
        }
        sort(rall(v));
        deque<ll> q;
        q.push_front(0);
        ll pos;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                q.push_front(v[i].ss);
            else
                q.push_back(v[i].ss);
        }
        vll ans(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            ll a = q.front();
            q.pop_front();
            ans[a] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            sum += vy[i] * 2 * abs(ans[0] - ans[i]);
        }
        cout << sum << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}