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

    freopen("coffee.in", "r", stdin);

    ll t;
    cin >> t;
    while (t--)
    {
        ll c, p;
        cin >> c >> p;
        map<string, vll> m;
        for (int i = 0; i < c; i++)
        {
            string s;
            cin >> s;
            vll v(3);
            for (auto &i : v)
                cin >> i;
            m[s] = v;
        }
        ll delivery = 100 / p;
        for (int i = 0; i < p; i++)
        {
            ll ans = 0;
            ans += delivery;
            string s, t, u;
            cin >> s >> t >> u;
            ll ind;
            if (t.front() == 's')
                ind = 0;
            else if (t.front() == 'm')
                ind = 1;
            else
                ind = 2;
            ans += m[u][ind];
            if (ans % 5 == 4)
                ans++;
            else if (ans % 5 == 1)
                ans--;
            cout << s << " " << ans << endl;
        }
    }
    return 0;
}