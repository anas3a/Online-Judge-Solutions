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

    ll nc, nt, np, ns;
    cin >> nc;
    vll vc(nc);
    for (auto &i : vc)
        cin >> i;
    sort(all(vc));
    cin >> nt;
    vll vt(nt);
    for (auto &i : vt)
        cin >> i;
    sort(all(vt));
    cin >> np;
    vll vp(np);
    for (auto &i : vp)
        cin >> i;
    sort(all(vp));
    cin >> ns;
    vll vs(ns);
    for (auto &i : vs)
        cin >> i;
    sort(all(vs));

    ll w = 0, x = 0, y = 0, z = 0;
    ll mn = INT_MAX;
    vll ans;
    for (int i = 0; i < nc; i++)
    {
        while (w < nt && vt[w] < vc[i])
            w++;
        while (x < np && vp[x] < vc[i])
            x++;
        while (y < ns && vs[y] < vc[i])
            y++;
        for (int j = 0; j < (1 << 3); j++)
        {
            vll anv;
            anv.pb(vc[i]);
            for (int k = 0; k < 3; k++)
            {
                bool f = false;
                if ((j & (1 << k)))
                    f = true;
                if (k == 0)
                {
                    if (f)
                        anv.pb(vt[w]);
                    else
                        anv.pb(vt[min(w + 1, nt - 1)]);
                }
                if (k == 1)
                {
                    if (f)
                        anv.pb(vp[x]);
                    else
                        anv.pb(vp[min(x + 1, np - 1)]);
                }
                if (k == 2)
                {
                    if (f)
                        anv.pb(vs[y]);
                    else
                        anv.pb(vs[min(y + 1, ns - 1)]);
                }
            }
            vll vz = anv;
            sort(all(anv));
            if (anv[3] - anv[0] < mn)
            {
                mn = anv[2] - anv[0];
                ans = vz;
            }
        }
    }
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
