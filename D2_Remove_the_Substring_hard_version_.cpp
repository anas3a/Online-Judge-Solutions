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

string s, t;
vll vf, vb;
bool ok(ll m)
{
    ll cnt = 0, ans = 0;
    for (int i = 0; i <= sz(s) - m; i++)
    {
        cnt = (i == 0) ? 0 : vf[i - 1];
        cnt += (i + m >= sz(s)) ? 0 : vb[i + m];
        ans = max(ans, cnt);
    }
    return ans >= sz(t);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    ll l = 0, r = sz(s) + 10;
    vf.assign(sz(s), 0);
    vb.assign(sz(s), 0);
    for (int i = 0, j = 0; i < sz(s); i++)
    {
        if (j < sz(t) && s[i] == t[j])
            j++;
        vf[i] = j;
    }
    for (int i = sz(s) - 1, j = sz(t) - 1; i >= 0; i--)
    {
        if (j >= 0 && s[i] == t[j])
            j--;
        vb[i] = sz(t) - j - 1;
    }
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (ok(m))
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}