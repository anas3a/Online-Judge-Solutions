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

struct g
{
    int r = 0, p = 0, s = 0;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s, x;
        cin >> x;
        s = 'x' + x;
        vector<g> v(n + 1);
        g tmp;
        tmp.r = tmp.p = tmp.s = 0;
        v[0] = tmp;
        for (int i = 1; i <= n; i++)
        {
            g tm;
            tm = v[i - 1];
            if (s[i] == 'R')
                tm.r++;
            else if (s[i] == 'P')
                tm.p++;
            else
                tm.s++;
            v[i] = tm;
        }
        ll cnt = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; i + j <= n; j++)
            {
                int k = n - i - j;
                int w = 0, l = 0;
                if (i != 0)
                {
                    w += min(i, v[i].s);
                    l += min(i, v[i].p);
                }
                if (j != 0)
                {
                    int z = v[i + j].r - v[i].r;
                    w += min(j, z);
                    l += min(j, v[i + j].s - v[i].s);
                }
                if (k != 0)
                {
                    int z = v[n].p - v[i + j].p;
                    w += min(k, z);
                    l += min(k, v[n].r - v[i + j].r);
                }
                if (w > l)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
