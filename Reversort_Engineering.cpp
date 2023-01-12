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

ll c;
ll mx;
set<int> st;
bool func(vi v)
{
    ll ans = 0;
    for (int i = 0; i < sz(v) - 1; i++)
    {
        for (int j = i; j < sz(v); j++)
        {
            if (i + 1 == v[j])
            {
                ans += j - i + 1;
                reverse(v.begin() + i, v.begin() + j + 1);
                break;
            }
        }
    }
    mx = max(ans, mx);
    if (ans == c)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> c;
        bool f = false;
        vi v;
        for (int i = 1; i <= n; i++)
            v.pb(i);
        mx = 0;
        do
        {
            func(v);
        } while (next_permutation(all(v)));
        cout << "Case #" << ++cs << ":";
        dg(mx);
        for (auto i : st)
            cout << i << " ";
        cout << endl;
        // if (f)
        // {
        //     for (auto &i : v)
        //         cout << " " << i;
        //     cout << endl;
        // }
        // else
        //     cout << " IMPOSSIBLE" << endl;
    }
    return 0;
}
