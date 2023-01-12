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
        set<string> s;
        for (int i = 0; i < n; i++)
        {
            string st;
            cin >> st;
            s.insert(st);
        }
        string sx, ans;
        for (int i = 0; i < n; i++)
        {
            sx += '0';
        }
        if (s.count(sx))
        {
            for (int i = 0; i < n; i++)
            {
                string sy = sx;
                sy[i] = '1';
                if (s.count(sy) == 0)
                {
                    ans = sy;
                    break;
                }
            }
        }
        else
            ans = sx;
        if (ans.empty())
        {
            ans = sx;
            ans[n - 1] = '1';
            ans[n - 2] = '1';
        }
        cout << ans << endl;
    }
    return 0;
}
