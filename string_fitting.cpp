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

    int t;
    cin >> t;
    while (t--)
    {
        int w;
        string s, sx;
        cin >> w >> s;
        vector<string> vs;
        for (int i = 0; i < sz(s); i++)
        {
            if (s[i] == '-')
            {
                vs.pb(sx);
                vs.pb("-");
                sx.clear();
            }
            else
                sx += s[i];
        }
        vs.pb(sx);
        for (int i = 0, z = w; i < sz(vs); i++)
        {
            if (sz(vs[i]) > z)
            {
                cout << endl
                     << vs[i];
                z = w - sz(vs[i]);
            }
            else
            {
                cout << vs[i];
                z -= sz(vs[i]);
            }
        }
        cout << endl;
    }
    return 0;
}