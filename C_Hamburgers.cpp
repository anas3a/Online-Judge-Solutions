#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long, long>;
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

    string x;
    cin >> x;
    ll b = 0, s = 0, c = 0, pb, ps, pc, nb, ns, nc, r, cnt = 0;
    for (int i = 0; i < sz(x); i++)
    {
        if (x[i] == 'B')
            b++;
        else if (x[i] == 'S')
            s++;
        else
            c++;
    }
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    ll mn = 1e5;
    if (b != 0)
        mn = min(mn, nb / b);
    if (s != 0)
        mn = min(mn, ns / s);
    if (c != 0)
        mn = min(mn, nc / c);
    cnt += mn;
    nb -= mn * b;
    ns -= mn * s;
    nc -= mn * c;
    ll pcost = (pb * b) + (ps * s) + (pc * c);
    while (r != 0)
    {
        if ((nb <= 0 || b == 0) && (ns <= 0 || s == 0) && (nc <= 0 || c == 0))
            break;
        if (nb < b)
        {
            if (r < pb * (b - nb))
                break;
            r -= pb * (b - nb);
            nb = b;
        }
        if (ns < s)
        {
            if (r < ps * (s - ns))
                break;
            r -= ps * (s - ns);
            ns = s;
        }
        if (nc < c)
        {
            if (r < pc * (c - nc))
                break;
            r -= pc * (c - nc);
            nc = c;
        }
        nb -= b;
        ns -= s;
        nc -= c;
        cnt++;
    }
    cnt += r / pcost;
    cout << cnt << endl;
    return 0;
}