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
        vll v(n);
        multiset<ll> st;
        for (auto &i : v)
            cin >> i, st.insert(i);
        map<ll, ll> vis;
        for (ll i = 1; i <= n; i++)
        {
            auto it = st.lower_bound(i);
            if (it != st.end() && *it == i)
            {
                st.erase(it);
                vis[i]++;
            }
        }
        bool flag = true;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                ll x = i * 2 + 1;
                auto it = st.lower_bound(x);
                if (it == st.end())
                {
                    flag = false;
                    break;
                }
                st.erase(it);
            }
        }
        if (flag)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}