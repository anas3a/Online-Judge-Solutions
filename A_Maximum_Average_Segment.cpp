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

ll n, d, a1, a2;
vi v;
double l, r, m;

bool f(double m)
{
    vector<double> vx(n + 1, 0)
    vector <pair <double, int>> vy(n + 1);
    for (int i = 1; i <= n; i++)
        vx[i] = v[i - 1];
    for (int i = 1; i <= n; i++)
        vx[i] += vx[i - 1] - m;
    double mn = 0, in = 0;
    for (int i = 1; i <= n; i++)
    {
        if(mn >= vx[i])
        {
            mn = min(mn, vx[i]);
            in = i;
        }
        vy[i] = {mn, in};
    }
    for (int i = d; i <= n; i++)
    {
        if (i == d)
        {
            if (vx[i] >= 0)
            {
                a2 = i;
                a1 = 1;
                return true;
            }
        }
        else
        {
            if (vx[i] >= vy[i - d].ff)
            {
                a2 = i;
                a1 = vy[i - d].ss + 1;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> d;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    l = -1, r = 300;
    for (int i = 0; i < 200; i++)
    {
        m = (l + r) / 2.0;
        if (f(m))
            l = m;
        else
            r = m;
    }
    f(l);
    cout << a1 << " " << a2 << endl;
    return 0;
}
