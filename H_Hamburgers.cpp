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

string ss;
ll b = 0, s = 0, c = 0, nb, ns, nc, pb, ps, pc, rb, cost;

bool f(ll x)
{
    ll bcost = cost * x;
    bcost -= min(x * b, nb) * pb;
    bcost -= min(x * s, ns) * ps;
    bcost -= min(x * c, nc) * pc;
    return bcost <= rb;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> ss >> nb >> ns >> nc >> pb >> ps >> pc >> rb;
    for (auto &i : ss)
    {
        if (i == 'B')
            b++;
        else if (i == 'S')
            s++;
        else
            c++;
    }
    cost = (b * pb) + (s * ps) + (c * pc);
    ll l = 0, r = 1;
    while (f(r))
        r *= 2;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (f(m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}
