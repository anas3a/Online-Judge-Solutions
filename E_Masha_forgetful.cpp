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
        ll n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (auto &i : v)
            cin >> i;
        string s;
        cin >> s;
        map<string, vpl> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < sz(v[i]) - 1; i++)
            {
                string sx;
                sx += v[i][j];
                sx += v[i][j + 1];
                mp[sx].pb({i, j});
            }
        }
        vvl vx;
        bool flag = true;
        for (int i = 0; i < sz(s) - 1; i += 2)
        {

        }
    }
    return 0;
}