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
#define nl '\n'
#define dg(x) cerr << #x << " = " << x << endl

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vll v(n), vx(n, 0);
        map<ll, ll> m;
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i)
                vx[i] = vx[i - 1];
            vx[i] += v[i];
            m[v[i]] = i;
            st.insert(v[i]);
        }
        while (q--)
        {
            ll k;
            cin >> k;
            ll ans = 0;
            auto it = st.lower_bound(k);
            if (it != st.begin() && *st.begin() > k)
                it--;
            if (*it <= k)
            {
                ans = *it;
            }
            cout << ans << " ";
        }
        cout << nl;
    }
    return 0;
}